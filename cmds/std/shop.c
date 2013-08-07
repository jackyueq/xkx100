// shop.c

inherit F_CLEAN_UP;

#include <ansi.h>;

int help(object me);

int main(object me, string arg)
{
        string name, id;
	seteuid(getuid());
        if (! arg)
        {
                SHOP_D->list_shop(me);
                return 1;
        }
        if (! wizardp(me))
                return notify_fail("��û��Ȩ��ʹ�õ��̹���ָ�\n");

        switch (arg)
        {
        case "all"   : SHOP_D->do_listall(me); break;
        case "open"  : SHOP_D->open_all(me); break;
        case "close" : SHOP_D->close_all(me); break;
        case "reset" : SHOP_D->reset_all(me); break;
        default :
                if (sscanf(arg, "open %s", name))
                {
                        SHOP_D->open_shop(me, name);
                        break;
                }
                if (sscanf(arg, "close %s", name))
                {
                        SHOP_D->close_shop(me, name);
                        break;
                }
                if (sscanf(arg, "reset %s", name))
                {
                        SHOP_D->reset_shop(me, name);
                        break;
                }
                if (sscanf(arg, "owner %s %s", name, id))
                {
                        SHOP_D->change_owner(me, name, id);
                        break;
                }
                else return help(me);
        }
        
        return 1;
}

int help (object me)
{
	write(@HELP

ָ���ʽ��shop [ open [��������] ]  | [ close [��������] ] |
               [ reset [��������] ] | [ owner <��������> <����ID> ]
               [ all ]

��Ҳ鿴��ǰ��Ϸ�еĵ��̾�Ӫ״����

��ʦ�������ڹ�����̣�
ʹ�� open ��������ָ����һ�����̻������е��̡�
ʹ�� close �������ر�ָ����һ�����̻������е��̡�
ʹ�� reset �������³�ʼ��ָ����һ�����̻������е��̡�
��ʹ��owner �����������õ����� id��
ʹ�� all ����ʾ�����̵���

HELP);
        return 1;
}


