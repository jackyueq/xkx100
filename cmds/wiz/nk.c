// npckill.c
#include <ansi.h>
int main(object me, string arg)
{ 
	object obj,dest; 
	string sb1, sb2;
//	if( environment(me)->query("no_fight") ) 
//		return notify_fail("���ﲻ׼ս����\n")
 	if( !arg || arg=="" )
		return notify_fail("ָ���ʽ��nk sb1 sb2\n");
 	if( !(sscanf(arg, "%s %s", sb1, sb2)==2) )
 		return notify_fail("ָ���ʽ��nk sb1 sb2\n");
 	if( sscanf(arg, "%s %s", sb1, sb2)==2 )
 	dest=(present(sb1, environment(me)));
	obj=(present(sb2, environment(me)));
 	if(sb1 == sb2)
		return notify_fail("����������ͬ��������\n");
 	if(!objectp(obj = present(sb1, environment(me))) ||
 		!objectp(dest = present(sb2, environment(me))))
	return notify_fail("����û�������ˡ�\n");
 	if( !obj->is_character() || obj->is_corpse() ||
		!dest->is_character() || dest->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
 	if( !living(obj) || !living(dest) )
		return notify_fail("�Ѿ����˲���ս���ˡ�\n");
 	message_vision(CYN "$N��$n˵����"+RANK_D->query_self(obj) + obj->query("name") + "�����" + RANK_D->query_respect(dest) + "�ĸ��У�\n"NOR, obj,dest);
	message_vision(CYN"$Nһ���֣�˵����"+RANK_D->query_self(dest) +"����ˡ�\n"NOR, dest);
 	obj->delete_temp("halted");
	dest->delete_temp("halted");
 	remove_call_out("check");
	call_out("check",2, obj, dest);
 	dest->set("qi",(int)dest->query("max_qi"));
	obj->set("qi",(int)obj->query("max_qi"));
 	dest->set("eff_qi",(int)dest->query("max_qi"));
	obj->set("eff_qi",(int)obj->query("max_qi"));
 	remove_call_out("fighting");
	call_out("fighting",2, obj, dest);
 	return 1;
}  
void fighting(object dest, object obj)
{
	obj->fight_ob(dest);
	dest->fight_ob(obj);
}
void check(object obj, object dest)
{
	string name1, name2;
	if (!obj->query("family/family_name") &&
		dest->query("family/family_name"))
	{
		name1 = "�����ɵ�" + obj->query("name");
		name2 = dest->query("family/family_name")+"��"+dest->query("name");
	}
	else if (!dest->query("family/family_name") &&
		obj->query("family/family_name"))
		{
			name1 = obj->query("family/family_name")+"��"+obj->query("name");
			name2 ="�����ɵ�" + dest->query("name");
		}
		else if (!dest->query("family/family_name") &&
			!obj->query("family/family_name"))
			{
				name1 = "�����ɵ�" + obj->query("name");
				name2 = "�����ɵ�" + dest->query("name");
			}
			else
			{
				name1 = obj->query("family/family_name")+"��"+obj->query("name");
				name2 = dest->query("family/family_name")+"��"+dest->query("name");
			}
	shout( HIG"�����䡿������ʽ��ʼ����"+name1+"��"+name2 + "��\n"NOR);
	write( HIG"�����䡿������ʽ��ʼ����"+name1+"��"+name2 + "��\n"NOR);
	call_out("observe",1,obj,dest);
}
int observe(object obj,object dest)
{
	if(obj->is_fighting())
 	{ 
		call_out("observe",1,obj,dest);
		return 1;
	}
 	obj->delete_temp("pending/fight");
	dest->delete_temp("pending/fight");
 	if ( !present(obj, environment(this_player())) )
 	{
		shout(HIG"�����䡿"+obj->query("name")+"��Ķ����ˣ�\n"NOR);
		write(HIG"�����䡿"+obj->query("name")+"��Ķ����ˣ�\n"NOR);
		return 1;
	}
 	if ( !present(dest, environment(this_player())) )
 	{
		shout(HIG"�����䡿"+dest->query("name")+"��Ķ����ˣ�\n"NOR);
		write(HIG"�����䡿"+dest->query("name")+"��Ķ����ˣ�\n"NOR);
		return 1;
	}
 	if (obj->query_temp("halted"))
	{
		obj->delete_temp("halted");
		shout(HIG"�����䡿"+obj->query("name")+"��;�������䣡\n"NOR);
		write(HIG"�����䡿"+obj->query("name")+"��;�������䣡\n"NOR);
		return 1;
	}
	if (dest->query_temp("halted"))
	{
		dest->delete_temp("halted");
		shout(HIG"�����䡿"+dest->query("name")+"��;�������䣡\n");
		write(HIG"�����䡿"+dest->query("name")+"��;�������䣡\n");
		return 1;
	}
 	if ( obj->query("qi")*2 > obj->query("max_qi"))
 	{
		if  (dest->query("qi")*2 > dest->query("max_qi"))
		{
			shout( HIG"�����䡿" + obj->query("name") + "��" + dest->query("name") + "���䲻��ʤ����\n"NOR);
			write( HIG"�����䡿" + obj->query("name") + "��" + dest->query("name") + "���䲻��ʤ����\n"NOR);
			return 1;
		}
		shout( HIG"�����䡿"+ obj->query("name") + "����սʤ" + dest->query("name") + "��\n"NOR);
		write( HIG"�����䡿"+ obj->query("name") + "����սʤ" + dest->query("name") + "��\n"NOR);
	}
	else
	{ 
		shout( HIG"�����䡿" + dest->query("name") + "����սʤ" + obj->query("name") + "��\n"NOR);
		write( HIG"�����䡿" + dest->query("name") + "����սʤ" + obj->query("name") + "��\n"NOR);
	} 
	return 1;
}
int help(object me)
{
	write(@HELP
ָ���ʽ : nk <����1> <����2>   ���ָ�����������NPC����һ�NPC����һ��๥����
HELP);
	return 1;
} 

