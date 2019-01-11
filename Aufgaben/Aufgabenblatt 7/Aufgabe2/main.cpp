//
// Created by Nicolas Haenni on 2019-01-11.
//
#import <iostream>
#import <iomanip>
#import <string>
#import <vector>

class FoodItem {
private:
    std::string name;
    double      weight;
    double      nutritionalValue;
    double      nutPerKg;

public:
    FoodItem(std::string n, double w, double v) : name(std::move(n)), weight(w), nutritionalValue(v) {
        this->nutPerKg = v / w;
    };

    std::string getName() const { return this->name; };

    double getWeight() const { return this->weight; };

    double getNutritionalValue() const { return this->nutritionalValue; };

    double getNutPerKg() const { return this->nutPerKg; };

    void setName(std::string& name) { this->name = name; };

    void setWeight(int weight) { this->weight = weight; };

    void setNutritionalValue(int val) { this->nutritionalValue = val; };
};

class KnapsackUtil {
public:
    static std::vector<FoodItem> solveProblem(std::vector<FoodItem>& foodlist, int payloadLimit);
};

std::vector<FoodItem> KnapsackUtil::solveProblem(std::vector<FoodItem>& foodlist, int payloadLimit) {
    std::vector<FoodItem> packed;
    double                remaining = static_cast<double>(payloadLimit);

    std::sort(foodlist.begin(), foodlist.end(),
              [](FoodItem a, FoodItem b) { return a.getNutPerKg() > b.getNutPerKg(); });

    std::vector<FoodItem>::iterator it = foodlist.begin(); // NOLINT

    while (remaining > 0 && it != foodlist.end()) {
        double amount    = it->getWeight() < remaining ? it->getWeight() : remaining;
        double nutrition = amount * it->getNutPerKg();
        packed.emplace_back(FoodItem(it->getName(), amount, nutrition));
        remaining -= amount;
        it++;
    }

    return packed;
}

int main(int argc, char** argv) {
    std::vector<FoodItem> foodlist;
    std::vector<FoodItem> foodPacked;

    foodlist.emplace_back(FoodItem("Sellerie", 12, 4));
    foodlist.emplace_back(FoodItem("Bonbons", 4, 10));
    foodlist.emplace_back(FoodItem("Knäckebrot", 2, 2));
    foodlist.emplace_back(FoodItem("Äpfel", 1, 2));
    foodlist.emplace_back(FoodItem("Karotten", 1, 1));

    std::cout << "Vorhandene FoodItems:" << std::endl;
    for (auto const& el : foodlist) {
        printf("%-11s\t(Gewicht: %2.2f, Nährwert: %2.2f (%2.2f pro kg)\n", el.getName().c_str(), el.getWeight(),
               el.getNutritionalValue(),
               el.getNutPerKg());
    }

    foodPacked = KnapsackUtil::solveProblem(foodlist, 10);

    std::cout << std::endl;
    std::cout << "Gepacke FoodItems:" << std::endl;
    for (auto const& el : foodPacked) {
        printf("%-11s\t(Gewicht: %2.2f, Nährwert: %2.2f (%2.2f pro kg)\n", el.getName().c_str(), el.getWeight(),
               el.getNutritionalValue(),
               el.getNutPerKg());
    }

    return 0;
}