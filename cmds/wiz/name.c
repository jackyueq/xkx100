// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string name, id ,to,what;
	object obj=me;
	if( !arg ) return notify_fail("��Ҫ��˭ȡʲô���֣�\n");
	if (sscanf(arg, "%s %s(%s)", to,name, id) == 3)
	{
				what="name";
				if (!obj=present(to, environment(me)))
				if (!obj=find_player(to))
							return notify_fail("û������ˡ�\n");
	}
	else if (sscanf(arg,"%s cancel",to)==1)
	{
				what="cancel";
				if (!obj=present(to, environment(me)))
				if (!obj=find_player(to))
							return notify_fail("û������ˡ�\n");
	}
	else if (sscanf(arg,"%s(%s)", name,id)==2)
	{
			 what="name";
	}
	else if (arg=="cancel") 
	{
			what="cancel";
	}
	else
	{
			return notify_fail("�﷨��ʽ��name [ĳ��] [cancel] [������(id)]\n");
	}
	if (what=="cancel")
	{
		if (!obj->query("old_name") || !obj->query("old_id"))
			return notify_fail(obj->query("name")+"��û����name�����������\n");
		else
		{
			write("��� "+obj->query("name")+"("+obj->query("id")+") ������");
			obj->set("id",obj->query("old_id"));
			obj->set("name",obj->query("old_name"));
			obj->delete("old_id");
			obj->delete("old_name");
			write("�ָ����� "+obj->query("name")+"("+obj->query("id")+") ��\n");
			return 1;
		}
	}
	else if (what=="name")
	{
	name = replace_string(name, "$BLK$", BLK);
	name = replace_string(name, "$RED$", RED);
	name = replace_string(name, "$GRN$", GRN);
	name = replace_string(name, "$YEL$", YEL);
	name = replace_string(name, "$BLU$", BLU);
	name = replace_string(name, "$MAG$", MAG);
	name = replace_string(name, "$CYN$", CYN);
	name = replace_string(name, "$WHT$", WHT);
	name = replace_string(name, "$HIR$", HIR);
	name = replace_string(name, "$HIG$", HIG);
	name = replace_string(name, "$HIY$", HIY);
	name = replace_string(name, "$HIB$", HIB);
	name = replace_string(name, "$HIM$", HIM);
	name = replace_string(name, "$HIC$", HIC);
	name = replace_string(name, "$HIW$", HIW);
	name = replace_string(name, "$NOR$", NOR);
	id = replace_string(id, "$BLK$", BLK);
	id = replace_string(id, "$RED$", RED);
	id = replace_string(id, "$GRN$", GRN);
	id = replace_string(id, "$YEL$", YEL);
	id = replace_string(id, "$BLU$", BLU);
	id = replace_string(id, "$MAG$", MAG);
	id = replace_string(id, "$CYN$", CYN);
	id = replace_string(id, "$WHT$", WHT);
	id = replace_string(id, "$HIR$", HIR);
	id = replace_string(id, "$HIG$", HIG);
	id = replace_string(id, "$HIY$", HIY);
	id = replace_string(id, "$HIB$", HIB);
	id = replace_string(id, "$HIM$", HIM);
	id = replace_string(id, "$HIC$", HIC);
	id = replace_string(id, "$HIW$", HIW);
	id = replace_string(id, "$NOR$", NOR);

	write("��� "+obj->query("name")+"("+obj->query("id")+") ");	
	obj->set("old_name",obj->query("name"));
	obj->set("old_id",obj->query("id"));
	obj->set("name", name);
	obj->set("id", id);
	write("����Ϊ "+obj->query("name")+"("+obj->query("id")+") ��\n");
	}
	else 
	{
		write("����Կ���������ҪЩbug������\n");
	}
	return 1;
}
int help(object me)
{
	write(@HELP
ָ���ʽ : name ����(id)
           name cancel
           name dami ����(dummy)
           name dami cancel
					 
 
�����ϣ����������ʹ��ansi�Ŀ�����Ԫ�ı���ɫ�����������µĿ���
�ִ���

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
