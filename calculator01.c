//  #include <stdio.h>
//
//  int main(void){
//      int num1, num2, result;
//          char opt = 0;
//              
//                  while(1){
//                          printf("수식을 입력하세요\n");
//                                  scanf("%d %c %d", &num1, &opt, &num2);
//                                          switch (opt){
//                                                      case '+':
//                                                                      result = num1 + num2;
//                                                                                      printf("%d %c %d = %d\n", num1, opt, num2, result);
//                                                                                                      break;
//                                                                                                                  case '-':
//                                                                                                                                  result = num1 - num2;
//                                                                                                                                                  printf("%d %c %d = %d\n", num1, opt, num2, result);
//                                                                                                                                                                  break;
//                                                                                                                                                                              case '*':
//                                                                                                                                                                                              result =num1 * num2;
//                                                                                                                                                                                                              printf("%d %c %d = %d\n", num1, opt, num2, result);
//                                                                                                                                                                                                                              break;
//                                                                                                                                                                                                                                          case '/':
//                                                                                                                                                                                                                                                          printf("%d/%d = %lf\n", num1, num2, (float)num1 / num2);
//                                                                                                                                                                                                                                                                          break;
//                                                                                                                                                                                                                                                                                      default:
//                                                                                                                                                                                                                                                                                                      printf("없는 연산자입니다");
//                                                                                                                                                                                                                                                                                                              }
//                                                                                                                                                                                                                                                                                                                      
//                                                                                                                                                                                                                                                                                                                          }
//                                                                                                                                                                                                                                                                                                                              return 0;
//                                                                                                                                                                                                                                                                                                                              }
