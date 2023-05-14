#include <stdio.h>
#include <stdlib.h>

int main() {
    // Inisialisasi PIN awal
    int pin = 605030;
    // Inisialisasi saldo awal
    float balance = 6530000;
    // Inisialisasi variabel-variabel lain yang dibutuhkan
    int choice, login_attempt = 0;
    int transfer_account_number;
    float transfer_amount, top_up_dana, top_up_cip_ungu_high_domino, top_up_shopepay, top_up_gopay, top_up_PLN, withdrawal_amount;

    // Loop while untuk mengulang login hingga maksimal 3 kali percobaan
    while (login_attempt < 3) {
        // Meminta pengguna memasukkan PIN
        int input_pin;
        printf("Enter PIN: ");
        scanf("%d", &input_pin);
        
        // Jika PIN benar, tampilkan menu opsi
        if (input_pin == pin) {
            printf("Login successful!\n");
            while (1) {
                printf("\nWELLCOME TO BANK CENTRAL ASIA RAIHAN RIZQULLAH\n");
                printf("\nATM BCA Menu\n");
                printf("1. Check Balance\n");
                printf("2. Deposit\n");
                printf("3. Withdraw\n");
                printf("4. Transfer\n");
                printf("5. Top Up\n");
                printf("6. Logout\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                
                // Switch case untuk setiap opsi pada menu
                switch (choice) {
                    case 1:
                        printf("Your current balance is: %.2f\n", balance);
                        break;
                    case 2:
                        printf("Enter amount to deposit: ");
                        float deposit_amount;
                        scanf("%f", &deposit_amount);
                        balance += deposit_amount;
                        printf("Deposit successful. Your new balance is: %.2f\n", balance);
                        break;
                    case 3:
                        printf("Enter amount to withdraw: ");
                        scanf("%f", &withdrawal_amount);
                        if (withdrawal_amount > balance) {
                            printf("Insufficient funds.\n");
                        } else {
                            balance -= withdrawal_amount;
                            printf("Withdrawal successful. Your new balance is: %.2f\n", balance);
                        }
                        break;
                    case 4:
                        printf("Enter account number to transfer: ");
                        scanf("%d", &transfer_account_number);
                        printf("Enter amount to transfer: ");
                        scanf("%f", &transfer_amount);
                        if (transfer_amount > balance) {
                            printf("Insufficient funds.\n");
                        } else {
                            balance -= transfer_amount;
                            printf("Transfer successful. Your new balance is: %.2f\n", balance);
                        }
                        break;
                    case 5:
                        printf("Top up menu\n");
                        printf("1. Top up Dana\n");
                        printf("2. Top up Cip Ungu High Domino\n");
                        printf("3. Top up Shopepay\n");
                        printf("4. Top up Gopay\n");
                        printf("5. PLN\n");
                        printf("Enter your choice: ");
                        int top_up_choice;
                        scanf("%d", &top_up_choice);
                        switch (top_up_choice) {
                            case 1:
                            	printf("Enter Nomor Dana to top up: ");
								scanf("%f", &top_up_dana);
                                printf("Enter amount to top up: ");
                                scanf("%f", &top_up_dana);
                                printf("Enter PIN: ");
                                scanf("%d", &pin);
                                printf("Top up successful. Your new balance is: %.2f\n", balance - top_up_dana);
                                break;
							case 2:
								printf("Enter id cip high domino to top up: ");
								scanf("%f", &top_up_cip_ungu_high_domino);
                                printf("Enter amount to top up: ");
                                scanf("%f", &top_up_cip_ungu_high_domino);
                                printf("Enter PIN: ");
                                scanf("%d", &pin);
                                printf("Top up successful. Your new balance is: %.2f\n", balance - top_up_cip_ungu_high_domino);
                                break;
							case 3:
								printf("Enter Nomor Shopepay to top up: ");
								scanf("%f", &top_up_shopepay);
                                printf("Enter amount to top up: ");
                                scanf("%f", &top_up_shopepay);
                                printf("Enter PIN: ");
                                scanf("%d", &pin);
                                printf("Top up successful. Your new balance is: %.2f\n", balance - top_up_shopepay);
                                break;
                            case 4:
                            	printf("Enter nomor gopay to top up: ");
								scanf("%f", &top_up_gopay);
                                printf("Enter amount to top up: ");
                                scanf("%f", &top_up_gopay);
                                printf("Enter PIN: ");
                                scanf("%d", &pin);
                                printf("Top up successful. Your new balance is: %.2f\n", balance - top_up_gopay);
                                break;
							case 5:
                            	printf("Enter id PLN to top up: ");
								scanf("%f", &top_up_PLN);
                                printf("Enter amount to top up: ");
                                scanf("%f", &top_up_PLN);
                                printf("Enter PIN: ");
                                scanf("%d", &pin);
                                printf("Top up successful. Your new balance is: %.2f\n", balance - top_up_PLN);
                                break;
							
                            default:
                                printf("Invalid option.\n");
                                break;
                        }
                        break;
                    case 6:
                        // Keluar dari menu dan kembali ke menu login
                        printf("Logout successful.\n");
                        login_attempt = 3;
                        break;
                    default:
                        printf("Invalid option.\n");
                        break;
                }
            }
        } else {
            // Jika PIN salah, tampilkan pesan error dan tingkatkan jumlah percobaan
            printf("Invalid PIN. Please try again.\n");
            login_attempt++;
        }
    }
    // Jika sudah 3 kali percobaan login dan masih gagal, keluar dari program
    if (login_attempt == 5) {
        printf("Too many failed attempts. ATM locked.\n");
    }
    return 0;
}