// title.c (Mon 09-04-95)
// ������ʦ�쿴���߻�������ҽ׼���ͷ�εĹ��ܡ�
// Modified by Spacenet@FXLT 1.16.2000
 
#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string name)
{
	object ob;
	
	seteuid(getuid());
	
	if (!wizardp(me) || !name)
	{
		printf(BOLD"%s"NOR"%s\n\n",RANK_D->query_rank(me),me->short(1));
    		return 1;
  }
    	
    	if (ob = LOGIN_D->find_body(name)) {
    		printf(BOLD"%s"NOR"%s\n\n",RANK_D->query_rank(ob),ob->short(1));
    		return 1;
    	}
	    ob = new(USER_OB);
    	seteuid(name);
    	export_uid(ob);
    	
    	if (!ob->restore())
    	{
    		destruct(ob);
    		return notify_fail("û�������ҡ�\n");
    	}
    	printf(BOLD "%s" NOR "%s\n", RANK_D->query_rank(ob), ob->short(1));
	printf("%s \n\n", "�����Ŀǰ�����ߡ�");	
	destruct(ob);
	return 1;
    	
}
 
int help(object me)
{
    write(@HELP
ָ���ʽ: title [�����]
 
    ����� title ������ʾĿǰ�Լ��Ľ׼���ͷ�Ρ�
    ��ʦ�� title + ����� ������ʾ����ҵĽ׼���ͷ�Ρ�
 
HELP
    );
}
 

