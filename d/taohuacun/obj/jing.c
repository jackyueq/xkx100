// jing.c
#include <ansi.h>;
inherit ITEM;
void create()
{
        set_name(HIG"������"NOR, ({"jing"}));
        set("unit", "��");
        set("long",HIG" 
�������������������� �������� ����������������������
����������������������������������������������������
����  bsave             �����浵����            ����
����  bteach/bjiao      ���̺����书��          ����
����  bexercise/bdazuo  ���ú��Ӵ�����������    ����
����  bpractice/blian   ���ú�����ϰ�书��      ����
����  blearn/bxue       ���ú�����ʦ��ѧϰ�书������
����  bstudy/bdu        ���ú��Ӷ���ѧ�书���ܡ�����
����  hp,score,skills   ���鿴����״̬��        ����
����  do <act>          �������ǵĺ��Ӹɻ�ȥ��  ����
����      Ŀǰdo֧���������                  ����
����  go   get     give   hit     fight kill    ����
����  wear remove  wield  unwield eat   drink   ����
����  jifa enable  jiali  enforce yun   exert   ����
����  bei  prepare fangqi abandon bai apprentice����
����                                            ����
����                          ������һ�ٹ���    ����
����������������������������������������������������
����������������������������������������������������
"NOR);
        set("value", 0);
        set_weight(10);
        setup();
}


