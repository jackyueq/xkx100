// /cmds/std/get.c

// Modified by Constant Jan 6 201

#include <ansi.h>

inherit F_CLEAN_UP;
int do_get(object me, object ob);
int all;
object i_have(object env,string name); // env��ȡ���� name����Ʒ
string filter_color(string arg);

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string from, item;
	object obj, *inv, env, obj2;
	int i, amount , res;
  string msg;

	all=0;
	if (!arg) return notify_fail("��Ҫ����ʲô������\n");
	if (me->is_busy())
		return notify_fail("����һ��������û����ɣ�\n");
	if (sscanf(arg, "%s from %s", arg, from) == 2)
	{
	//	env = present(from, me);
	    env = i_have(me,from);
//		if (!env) env = present(from, environment(me));
		if (!env) env = i_have(environment(me),from);
		if (!env)
			return notify_fail("���Ҳ��� "+from+" ����������\n");
		if ((env->query("no_get_from") ||
			living(env) && !env->query_temp("noliving/unconcious")) 
			&& (wiz_level(me) <= wiz_level(env)))
			return notify_fail("�����ʦ�ȼ�����ȶԷ��ߣ�����������\n");
	} else env = environment(me);

	if (sscanf(arg, "%d %s", amount, item) == 2)
	{
	//	if (!objectp(obj = present(item, env)))
		if( !objectp(obj = i_have( env,item )) ) // env have item	
			return notify_fail("����û������������\n");
		if (!obj->query_amount())
			return notify_fail(obj->name() + "���ܱ��ֿ����ߡ�\n");
		if (amount < 1)
			return notify_fail("�����ĸ���������һ����\n");
		if (amount > obj->query_amount())
			return notify_fail("����û��ô���"+obj->name()+"��\n");
		else
			if(amount == (int)obj->query_amount())
				return do_get(me, obj);
			else
			{
				obj2 = new(base_name(obj));
				obj2->set_amount((int)obj->query_amount()-amount);
				obj->set_amount( amount );
				res=do_get(me, obj);
				obj2->move(env);
//				if (me->is_fighting())
//					me->start_busy(3);
				return res;
			}
	}
	if (arg=="all")
	{
		if (me->is_fighting())
			return notify_fail("�㻹��ս���У�ֻ��һ����һ����\n");
		if (!env->query_max_encumbrance())
			return notify_fail("�ǲ���������\n");
   	if (env->is_tree())
   		return notify_fail("���Ǹ����ֻ����õģ����ǲ�Ҫ̫̰���˰ɣ\n");
		inv = all_inventory(env);
		if (!sizeof(inv))
		{
   		if (env->is_tree())
         		return notify_fail("����ʲôҲû���ˡ�\n");
			return notify_fail("������û���κζ�����\n");
   	}        	
    if (sizeof(inv)>=20) all=1;
		for (i = 0; i < sizeof(inv); i ++)
		{
			if (inv[i]->is_character() 
			|| inv[i]->query("no_get")
			||inv[i]->query("taskobj")
			||inv[i]->query("owner"))
				continue;
			
			do_get(me, inv[i]);
		}
    if (env->is_character())
        msg = "$N��" + env->name() + "�����ѳ���һ�Ѷ�����\n";
    else
     if (env == environment(me))
        msg = "$N�ѵ��ϵĶ���������������\n";
     else
        msg = "$N��" + env->name() + "����Ķ��������˳�����\n";
 
		if (all!=1)
		write("����ˡ�\n");
	  else
	   message_vision(msg,me);
		return 1;
	}
//	if (!objectp(obj = present(arg, env)))
	if( !objectp(obj = i_have( env,arg )) ) // me have item	
		return notify_fail("�㸽��û������������\n");
	else
		if( userp(obj))
		{
			if(!obj->query_temp("noliving/unconcious") )
				return notify_fail("�㸽��û������������\n");
		}
		else
		{
			if(living(obj))
				return notify_fail("�㸽��û������������\n");
		}

	if (obj->query("no_get"))
	  if (stringp(obj->query("no_get")))
      return notify_fail(obj->query("no_get"));
    else
  		return notify_fail("��������ò�������\n");
	return do_get(me, obj);
}

int do_get(object me, object obj)
{
	object old_env, *guard, owner;
	int equipped;
	string msg = "";
	mapping quest;

	if (!obj) return 0;
	old_env = environment(obj);
	if (obj->query("no_get")) return 0;
	if (obj->query_temp("is_rided_by")) return 0;
        if (userp(obj) && obj->query_temp("LAST_PKER_TIME"))
                 return notify_fail("���˸�ɱ���ˣ��㻹������Ϊ��!\n");
        if (userp(obj) && obj->is_ghost() && !wizardp(obj))
                 return notify_fail("�ⶫ���ò�����!\n");

        if (obj->is_character())
	{
		if (userp(obj))
		{
			if(!obj->query_temp("noliving/unconcious")) return 0;
		}
		else if (living(obj)) return 0;
	} else
		if (obj->query("no_get")) return 0;
	if (guard = obj->query_temp("guarded"))
	{
		guard = filter_array(guard, (:objectp($1) && present($1, environment($2)) && living($1) && ($1!=$2):), me);
		if (sizeof(guard))
			return notify_fail(guard[0]->name() + "������" + obj->name() + "һ�ԣ���ֹ�κ������ߡ�\n");
	}
	if (obj->query("equipped")) equipped = 1;
// ����task dummy
	if (obj->move(me))
	{
		if (me->is_fighting()) me->start_busy(1);
		if (all!=1 )
		if (obj->is_character())
			message_vision("$N��$n�����������ڱ��ϡ�\n", me, obj);
		else
		{
			msg += "$N";
			if (old_env == environment(me))
				msg += "����";
			else if (old_env->is_character())
				msg += "��" + old_env->name() + "����" + (equipped?"����":"�ѳ�"); 
				else if (old_env->is_tree())
					msg += "��" + old_env->name() + "ժ��";
					else
					msg += "��" + old_env->name() + "�ó�";
			msg += "һ" + obj->query("unit");
			msg += "$n��\n";

			message_vision(msg, me, obj);
			// ԭ��д���ɶ��Խϲ��Ϊ�����д����
			// Added by Constant Jan 6 2001
/*
			message_vision(sprintf("$N%sһ%s$n��\n",
					old_env==environment(me)?
						"����"
					:(old_env->is_character()?
					  	"��" + old_env->name() + "����" + (equipped?"����":"�ѳ�")
					:(old_env->is_tree()?
					  	"��" + old_env->name() + "��ժ��"
					:"��" + old_env->name() + "���ó�")),
					obj->query("unit")), 
					me, obj);
*/
		}
		
		// ����������Ʒ����Ϣ��ʾ��
		// Added by Constant Jan 6 2001		
		if (quest = obj->query("dynamic_quest"))
		{
			if (wizardp(me) && me->query("env/no_task_msg"))
				return 1;
			if (obj->query("taskobj") && !obj->query("owner"))
			{
				obj->set("owner", me->query("id"));
				if (!objectp(owner=find_object(quest["owner_name"])))
					owner=load_object(quest["owner_name"]);
					message("channel:snow", HIY"�����š�"HIG + me->query("name") + "�ҵ�" + owner->query("name") + HIG"��"NOR + obj->query("name") + HIG"����\n"NOR, users());
			}
		}
		return 1;
	}
//	else return 0;
	else return notify_fail(obj->query("name")+"�������̫���ˡ�\n");
}
object i_have(object env,string name)
{
	int i;
	object *inv;
	object obj;
	if (objectp(obj = present(name,env))) return obj;
	inv=all_inventory(env);
	for(i=0;i<sizeof(inv);i++)
	{
		if (filter_color(inv[i]->query("name"))==name)
		return inv[i];
	}
	return 0;
}
string filter_color(string arg)
{
  if(!arg) return "";
  arg = replace_string(arg, BLK, "");
  arg = replace_string(arg, RED, "");
  arg = replace_string(arg, GRN, "");
  arg = replace_string(arg, YEL, "");
  arg = replace_string(arg, BLU, "");
  arg = replace_string(arg, MAG, "");
  arg = replace_string(arg, CYN, "");
  arg = replace_string(arg, WHT, "");
  arg = replace_string(arg, HIR, "");
  arg = replace_string(arg, HIG, "");
  arg = replace_string(arg, HIY, "");
  arg = replace_string(arg, HIB, "");
  arg = replace_string(arg, HIM, "");
  arg = replace_string(arg, HIC, "");
  arg = replace_string(arg, HIW, "");
  arg = replace_string(arg, NOR, "");
/*  arg = replace_string(arg, BBLK, "");
  arg = replace_string(arg, BRED, "");
  arg = replace_string(arg, BGRN, "");
  arg = replace_string(arg, BYEL, "");
  arg = replace_string(arg, BBLU, "");
  arg = replace_string(arg, BMAG, "");
  arg = replace_string(arg, BCYN, "");
  arg = replace_string(arg, HBRED, "");
  arg = replace_string(arg, HBGRN, "");
  arg = replace_string(arg, HBYEL, "");
  arg = replace_string(arg, HBBLU, "");
  arg = replace_string(arg, HBMAG, "");
  arg = replace_string(arg, HBCYN, "");
  arg = replace_string(arg, HBWHT, "");
  arg = replace_string(arg, NOR, "");
*/
  return arg;
}
int help(object me)
{
	write(@HELP
ָ���ʽ : get <��Ʒ����> [from <������>]
           get <��Ʒ����>
           get all

    ���ָ��������������ϻ������ڵ�ĳ����Ʒ���������������ܼ�
����Ʒȫ��������

HELP
    );
    return 1;
}

