// weight.c
// created by doing

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        object env;
        int origin;
	      string msg;
        string to;

        if (!arg)
        {
         	 write("������������"+me->query_weight()+"����"+me->query_encumbrance()+"��\n");
           return 1;
        }
        else if (arg=="-1")
        {
         	me->set_weight(40000+(me->query("str") - 10)*2000);
          write("������ػָ���ԭ����"+me->query_weight()+"��\n");
          return 1;
        }
        else if (sscanf(arg,"%d",origin)==1)
        {
        	if ( origin < 200)
        	 origin=200;
         	me->set_weight(origin);
          write("������ص���Ϊ"+me->query_weight()+"��\n");
          return 1;
        }
        else
          help(me);
       	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : wieght [��ֵ| -1]
 
���ָ���ʹ��������仯�����������-1�ͻָ�ԭ�������ء�
 
HELP );
    return 1;
}
