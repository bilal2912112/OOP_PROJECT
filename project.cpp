#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
using namespace std;
class drug{
	protected:
     	char drug_name[20];
		char id[7];
		public:
			drug(){
				strcpy(drug_name,"");
				strcpy(id,"no id");
			}
			void setdata();
			string getdata();
			void show(){
				cout<<" drug name: "<<drug_name<<" ID:"<<id<<endl;
			}
};
class database:public drug{
	protected:
		float sale_price;
		float purchase_price;
		float profit;
		float total_drug;
		float drug_sale;
		float drug_left;
		float manufacture_date;
		float manufacture_month;
		float manufacture_year;
		float expire_date;
		float expire_month;
		float expire_year;
	    float validity_date;
	    
	public:
		database(){
		sale_price=0.0;
     	purchase_price=0.0;
	    total_drug=0.0;
		drug_sale=0.0;
	    manufacture_date=0.0;
		manufacture_month=0.0;
	    manufacture_year=0.0;
	    expire_date=0.0;
		expire_month=0.0;
		expire_year=0.0;
	   }
	     void setdata(){
			cout<<"Enter Name of drug:\n";
			cin.ignore();
			cin.getline(drug_name,19);
       		cout<<"Enter ID:\n";
			cin.getline(id,6);
			}
			string getdata(){
				return drug_name;
				return id;
			}
			void settingvalues(){
				system("cls");
				cout<<"Enter sales price\n";
				cin>>sale_price;
					cout<<"Enter  purchase_price\n";
				cin>>purchase_price;
					cout<<"Enter  total_drug\n";
				cin>>total_drug;
					cout<<"Enter  drug_sale\n";
				cin>>drug_sale;
					cout<<"Enter  manufacture_date\n";
				cin>>manufacture_date;
					cout<<"Enter  manufacture_month\n";
				cin>>manufacture_month;
					cout<<"Enter  manufacture_year\n";
				cin>>manufacture_year;
					cout<<"Enter  expire_date\n";
				cin>>expire_date;
				cout<<"Enter  expire_month\n";
				cin>>expire_month;
				cout<<"Enter  expire_year\n";
				cin>>expire_year;
				 system("cls");
				}
	float getvalues(){
			return sale_price;
		return purchase_price;	
		return total_drug;
		return drug_sale;
    	return manufacture_date;
	return manufacture_month;
	return  manufacture_year;
	return expire_date;
	return expire_month;
	return expire_year;
	   }
	    int storename_id(){
			ofstream foutna_id;
          	foutna_id.open("Name_ID.txt",ios::app|ios::binary);
          foutna_id.write((char*)this,sizeof(*this));
          	foutna_id.close();
          }
	void viewname_id(){
		system("cls");
		ifstream fin;
		fin.open("Name_ID.txt");
		if(!fin){
			cout<<"Find not exist\n";
		}
		else{
			fin.read((char*)this,sizeof(*this));//first we store data into caller object from the txt file and 
			//we cant directly call object by it name istead we use this
			//this is pointer which countain caller object.after that we are type casting char*.
		   //*this pointer is pointing caller object.
		  while(!fin.eof()){
		   	show();
		   	fin.read((char*)this,sizeof(*this));
		   	}
		}
		fin.close();
			system("pause");
          	system("cls");
	}
	int getprofit(){
		if(sale_price==0&&purchase_price==0){
			cout<<"Sorry data havent input\n";
		}
		else{
		
		if(sale_price>=purchase_price)
		{
		profit=sale_price-purchase_price;
			ofstream fout;
          	fout.open("profit.txt",ios::app|ios::binary);
          	//fout.write((char*)this,sizeof(*this));
          	fout<<sale_price<<endl;
          	fout<<purchase_price<<endl;
          	fout<<profit<<endl;
          	fout.close();
			  }
			  else{
			  	cout<<"you are in loss\n";
			  }
          }
    }
     void viewprofit(){
		system("cls");
			ifstream fin1;
		fin1.open("profit.txt");
		if(!fin1){
			cout<<"Find not exist\n";
		}
		else{
			cout<<"<----profit----->\n";
				cout<<"sale price\n";
		   		fin1>>sale_price;
		   		cout<<sale_price;
				   cout<<"\npurchase price\n";
				   fin1>>purchase_price;
				    cout<<purchase_price;
				   cout<<"\nprofit\n";
				   fin1>>profit;
				   cout<<profit<<endl;
		 }
		fin1.close();
			system("pause");
          	system("cls");
	}
    int getamount(){
		if(total_drug==0&&drug_sale){
			cout<<"Sorry data havent input\n";
		}
		else{
		drug_left=total_drug-drug_sale;
		ofstream fout1;
          	fout1.open("leftamount.txt",ios::app|ios::binary);
          	fout1<<total_drug<<endl;
          	fout1<<drug_sale<<endl;
          	fout1<<drug_left<<endl;
          	fout1.close();
		}
		}
		void viewamount(){
			system("cls");
			ifstream fin2;
		fin2.open("leftamount.txt");
		if(!fin2){
			cout<<"Find not exist\n";
		}
		else{
			cout<<"<----Amount left----->\n";
				cout<<"total_drug\n";
		   		fin2>>total_drug;
		   		cout<<total_drug;
				   cout<<"\ndrug_sale\n";
				   fin2>>drug_sale;
				    cout<<drug_sale;
				   cout<<"\ndrug_left\n";
				   fin2>>drug_left;
				   cout<<drug_left<<endl;
		 }
		fin2.close();
			system("pause");
          	system("cls");
	}
		
		
	int validityperiod(){
		
	 // validity_date=manufacture_date-expire_date;
	    
	     	ofstream fout2;
          	fout2.open("Validity.txt",ios::app|ios::binary);
          	fout2<<manufacture_date<<"-"<<manufacture_month<<"-"<<manufacture_year<<endl;
          	fout2<<expire_date<<"-"<<expire_month<<"-"<<expire_year<<endl;
       
		  //	fout2<<validity_date<<endl;
          	fout2.close();
	         }
	     	void viewdate(){
	     		system("cls");
			ifstream fin3;
		fin3.open("Validity.txt");
		if(!fin3){
			cout<<"Find not exist\n";
		}
		else{
			cout<<"<----Validity----->\n";
				cout<<"->Manufacture date dd/mm/yy:\n";
		   		fin3>>manufacture_date;
		   		cout<<manufacture_date;
		   		
		   		fin3>>manufacture_month;
		   		cout<<manufacture_month;
		   	
		   		fin3>>manufacture_year;
		   		cout<<manufacture_year;
				   cout<<"\n->Expire Date dd/mm/yy:\n";
				  fin3>>expire_date;
		   		cout<<expire_date;
		   		
		   		fin3>>expire_month;
		   		cout<<expire_month;
		   		
		   		fin3>>expire_year;
		   		cout<<expire_year;
				   cout<<"\n->Best before dd/mm/yy:\n";
				   
				   
				   fin3>>expire_date;
		   		cout<<expire_date;
		   		
		   		fin3>>expire_month;
		   		cout<<expire_month;
		   		
		   		fin3>>expire_year;
		   		cout<<expire_year<<endl;
		   	}
		
		fin3.close();
		system("pause");
          	system("cls");
	}
		
};
int main(){
	int choice;
	 database d1;
	do{
		cout<<"\n<------Dispansary Management System------>"<<endl;
		cout<<"->1:Enter data"<<endl;
		cout<<"->2:Show Name and ID"<<endl;
		cout<<"->3:Show Profit"<<endl;
		cout<<"->4:Amount Left"<<endl;
		cout<<"->5:Expire date"<<endl;
		cout<<"->6:Exit\n";
		cout<<"->Enter any choice"<<endl;
		cin>>choice;
		system("cls");
		switch(choice)
		{
			case 1:
			  
			   d1.setdata();
			   d1.storename_id();
			   d1.settingvalues();
			   d1.getprofit();
			   d1.getamount();
			   d1.validityperiod();
				break;
				case 2:
					d1.viewname_id();
					
					break;
					case 3:
				d1.viewprofit();
						break;
						case 4:
							d1. viewamount();
							break;
							case 5:
								d1.viewdate();
								break;
						case 6:
							exit(1);
							break;
							default:
								cout<<"Enter wrong input"<<endl;
		}
		
	}while(1);
	

}
