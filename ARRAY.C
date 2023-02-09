#include<stdio.h>
#include<conio.h>
#define size 50
int a[size],i,n;
void insert_element(){
	int m;
	printf("\n****** Inserting an element in array *****\n");
	do{
		clrscr();
		printf("Enter no of element you want to insert(max=%d):",size-n);
		scanf("%d",&m);
	}while(m>(size-n));

	for(i=n;i<n+m;i++){
		printf("N%d=",i+1);
		scanf("%d",&a[i]);
	}
	n=n+m;
	printf("\nInserting elements Successfully...\n");
}
void display(){
	printf("\n****** Array Elements ********\n[ ");
	for(i=0;i<n-1;i++){
		printf("%d,",a[i]);
	}
	printf("%d ]\n",a[i]);
}
void delete_element(){
	int flag,ele,j;
	printf("\nEnter element to be delete:");
	scanf("%d",&ele);
	for(i=0;i<n;i++){
		if(ele==a[i]){
			flag=1;
			for(j=i;j<n-1;j++){
				a[j]=a[j+1];
			}
			a[j]=NULL;
			n--;
		}
	}
	if(flag!=1)
		printf("\nElement not found...\n");
}
int delete_Index_element(){
	int index;
	printf("\nEnter index of element to be delete:");
	scanf("%d",&index);
	for(i=index;i<n-1;i++)
			a[i]=a[i+1];
	a[i]=NULL;
	n--;
	printf("\nDelete %d index element successfull...\n");
	return index;
}
int insert_element_index(){
	int index,ele;
	printf("\nEnter element to be insert:");
	scanf("%d",&ele);
	printf("\nEnter index no. where want to insert:");
	scanf("%d",&index);
	n++;
	for(i=n-1;i>index;i--)
			a[i]=a[i-1];
	a[index]=ele;
	printf("\nInsert Element at %d index successfull...\n",index);
	return index;
}
void short_array(){
	int j,min,temp;
	for(i=0;i<n;i++){
		min=a[i];
		for(j=i+1;j<n;j++){
			if(min>a[j]){
				temp=min;
				min=a[j];
				a[j]=temp;
			}
		}
		a[i]=min;
       }
}
void main(){
	int choice,index;
	char ch;
	do{
		clrscr();
		printf("**************** Array operation **********");
		do{
			printf("\nEnter no of element(max=%d):",size);
			scanf("%d",&n);
		}while(n>size);
		printf("Enter %d element one by one:\n",n);
		for(i=0;i<n;i++){
			printf("N%d:",i+1);
			scanf("%d",&a[i]);
		}
		do{
			printf("\n****** Arry operation perform ******\n");
			printf("1.Insert an element(at last index)\n");
			printf("2.Delete particular element\n");
			printf("3.Delete an element (from particular index)\n");
			printf("4.Insert an element in a particular index\n");
			printf("5.Shorting ArrayList\n");
			printf("0.Again Create array\n");
			printf("Enter your choice:");
			scanf("%d",&choice);
			switch(choice){
				case 1:
					insert_element();
					printf("\nAfter inserting an element in Array list:\n");
					display();
					break;
				case 2:
					delete_element();
					printf("\nAfter deleting an element in Array list:\n");
					display();
					break;
				case 3:
					index=delete_Index_element();
					printf("\nAfter deleting an element from %d Index in Array list:\n",index);
					display();
					break;
				case 4:
					index=insert_element_index();
					printf("\nAfter inserting an element at %d index in Array list:\n",index);
					display();
					break;
				case 5:
					short_array();
					printf("\nAfter shorting Your elements:\n");
					display();
				case 0:
					break;
				default:
					printf("\nInvalid input\n");
			}
			if(choice!=0){
				printf("\n Do you want to continue(y/n):");
				ch=getch();
			}
			else
			ch='n';

		}while(ch=='y'||ch=='Y');
		printf("\nAgain Create an Array list(y/n):");
		ch=getch();

	}while(ch=='y'||ch=='Y');
}