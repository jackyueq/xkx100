// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg ) return notify_fail("��Ҫ���Լ�ȡʲô�ºţ�\n");
	if( arg == "none" ) 
	{
		me->delete("nickname");
		write("��Ĵº�ȡ���ˡ�\n");
		return 1;
	}
	if( !wizardp(me) && strlen(arg) > 30 )
		return notify_fail("��Ĵº�̫���ˣ���һ����һ��ġ�����һ��ġ�\n");

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	me->set("nickname", arg + NOR);
	write("��ȡ���˴ºš�\n");
	return 1;
}
int help(object me)
{
	write(@HELP
ָ���ʽ : nick <���, �º�> | none
 
    ���ָ���������Ϊ�Լ�ȡһ�����������Ż�ͷ�Σ�nick none
ȡ���ºš������ϣ���ڴº���ʹ��ansi�Ŀ�����Ԫ�ı���ɫ������
�����µĿ����ִ���������ϵͳ�Զ������ִ�β�˼�һ�� $NOR$��

        $�£̣�$��[30m��ɫ[0m          
        $�ңţ�$��[31m��ɫ[0m          $�ȣɣ�$��[1;31m����ɫ[0m
        $�ǣң�$��[32m��ɫ[0m          $�ȣɣ�$��[1;32m����ɫ[0m
        $�٣ţ�$��[33m����ɫ[0m        $�ȣɣ�$��[1;33m��ɫ[0m
        $�£̣�$��[34m����ɫ[0m        $�ȣɣ�$��[1;34m��ɫ[0m
        $�ͣ���$��[35mǳ��ɫ[0m        $�ȣɣ�$��[1;35m�ۺ�ɫ[0m
        $�ã٣�$��[36m����ɫ[0m        $�ȣɣ�$��[1;36m����ɫ[0m
        $�ףȣ�$��[37mǳ��ɫ[0m        $�ȣɣ�$��[1;37m��ɫ[0m
        $�Σϣ�$��[0m�ָ�������ɫ[0m

HELP
	);
	return 1;
}
