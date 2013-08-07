//inventory.c
// Modified by Spacenet@FXLT

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i, j, *count=({});
	object *inv, *inv1=({}), ob;
	string str;
	string *invname=({});

  if (wizardp(me) && arg)
  {
  	ob = present(arg, environment(me));
  	if (!ob) ob = find_player(arg);
  	if (!ob) ob = find_living(arg);
  }
  else if ( !wizardp(me) && arg )
  {
  	ob = present(arg, environment(me));
	  if ( ob && !ob->is_baby() )
  	   ob = me;
    else 
    if ( ob && ob->is_baby() && member_array(me->query("id"),ob->query("parents")) < 0 ) 
        return notify_fail("ֻ�е����ܲ쿴�������ϵĶ�����");
  }
  if (!ob) ob = me;
	inv = all_inventory(ob);
	if( !sizeof(inv) )
	{
		write((ob==me)? "Ŀǰ������û���κζ�����\n"
			: ob->name() + "����û��Я���κζ�����\n");
		return 1;
	}
	for (i = 0;i < sizeof(inv);i ++)
    {
      if (me->visible(inv[i]))
      {
       	j=member_array( inv[i]->short()+"/"+inv[i]->query("id")+"/"+inv[i]->query("equipped"),invname );
		  	if (j == -1  )
		  	{
		  		inv1 += ({inv[i]});
		  		invname += ({ inv[i]->short() + "/" + inv[i]->query("id")+"/"+inv[i]->query("equipped") });
		  		count += ({1});
		  	} else 	
		  		count[j] += 1;
		  }
		}
 
	printf("%s���ϴ���������Щ����(���� %d%%)��\n", (ob==me)? "��": ob->name(), (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance());
	for (i = 0;i < sizeof(inv1);i ++)
	{
		printf("%s%s%s%s \n",inv1[i]->query("equipped") ? ((inv1[i] == me->query_temp("secondary_weapon")) ? HIC "��" NOR: HIC "��" NOR): "  ",
			(inv1[i]->query("base_unit") || inv1[i]->query("equipped"))?"":chinese_number(count[i]), 
			(inv1[i]->query("base_unit") || inv1[i]->query("equipped"))?"":inv1[i]->query("unit"),
			inv1[i]->short());
	}		
	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ: inventory
 
    ���г���Ŀǰ������Я����������Ʒ��
    ����ʾ���ֱ��������ʾ���ֱ�����

ע : ��ָ����� " i " ���档
 
HELP
);
	return 1;
}

