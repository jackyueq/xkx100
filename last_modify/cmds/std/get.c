// /cmds/std/get.c

// Modified by Constant Jan 6 201

#include <ansi.h>

inherit F_CLEAN_UP;

int do_get(object me, object ob);

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string from, item;
	object obj, *inv, env, obj2;
	int i, amount;

	if (!arg)
		return notify_fail("��Ҫ����ʲô������\n");

	if (me->is_busy())
		return notify_fail("����һ��������û����ɣ�\n");

	if (sscanf(arg, "%s from %s", arg, from) == 2) {
		env = present(from, me);
		if (!env)
			env = present(from, environment(me));
			
		if (!env)
			return notify_fail("���Ҳ��� " + from + " ����������\n");
			
		if ((env->query("no_get_from") || living(env))
			&& (wiz_level(me) <= wiz_level(env)))
			return notify_fail("�����ʦ�ȼ�����ȶԷ��ߣ���������\n");
	} else
		env = environment(me);

	if (sscanf(arg, "%d %s", amount, item) == 2) {
		if (!objectp(obj = present(item, env)))
			return notify_fail("����û������������\n");
			
		if (!obj->query_amount())
			return notify_fail(obj->name() + "���ܱ��ֿ����ߡ�\n");
			
		if (amount < 1)
			return notify_fail("�����ĸ���������һ����\n");

		if (amount > obj->query_amount())
			return notify_fail("����û��������" + obj->name() + "��\n");
		else if(amount == (int)obj->query_amount())
			return do_get(me, obj);
		else {
			obj2 = new(base_name(obj));
			obj2->set_amount((int)obj->query_amount() - amount);
			obj->set_amount( amount );
			do_get(me, obj);
			obj2->move(env);
			if (me->is_fighting())
				me->start_busy(3);
			return 1;
		}
	}

	if (arg=="all") {
		if (me->is_fighting())
			return notify_fail("�㻹��ս���У�ֻ��һ����һ����\n");
			
		if (!env->query_max_encumbrance())
			return notify_fail("�ǲ���������\n");
			
        	if (env->is_tree())
        		return notify_fail("���Ǹ����ֻ����õģ����ǲ�Ҫ̫̰���˰ɣ\n");

		inv = all_inventory(env);
		if (!sizeof(inv)) {
        		if (env->is_tree())
                		return notify_fail("����ʲôҲû���ˡ�\n");
			return notify_fail("������û���κζ�����\n");
        	}

		for (i = 0; i < sizeof(inv); i ++) {
			if (inv[i]->is_character() || inv[i]->query("no_get"))
				continue;
			do_get(me, inv[i]);
		}
		write("����ˡ�\n");
		return 1;
	}

	if (!objectp(obj = present(arg, env)) || living(obj))
		return notify_fail("�㸽��û������������\n");

	if (obj->query("no_get"))
		return notify_fail("��������ò�������\n");

	return do_get(me, obj);
}

int do_get(object me, object obj)
{
	object old_env, *guard, owner;
	int equipped;
	string msg = "";
	mapping quest;

	if (!obj)
		return 0;

	old_env = environment(obj);

	if (obj->query("no_get"))
		return 0;

	if (obj->is_character()) {
		if (living(obj))
			return 0;
	} else if (obj->query("no_get"))
		return 0;

	if (guard = obj->query_temp("guarded")) {
		guard = filter_array(guard, (:objectp($1) && present($1, environment($2)) && living($1) && ($1!=$2):), me);
		if (sizeof(guard))
			return notify_fail(guard[0]->name() +
					   "������" + obj->name() +
					   "һ�ԣ���ֹ�κ������ߡ�\n");
	}

	if (obj->query("equipped"))
		equipped = 1;

	if (obj->move(me)) {

		if (me->is_fighting())
			me->start_busy(1);

		if (obj->is_character())
			message_vision("$N��$n�����������ڱ��ϡ�\n", me, obj);
		else {
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
		if (quest = obj->query("dynamic_quest")) {
			if (!objectp(owner = find_object(quest["owner_name"])))
				owner = load_object(quest["owner_name"]);

			message("system", HIY"�����š�"HIG 
						+ me->query("name") 
						+ "�ҵ�" 
						+ owner->query("name")
						+ HIG"��"NOR + obj->query("name") + HIG"����\n"NOR, 
				users());
		}
		return 1;
	}
	else
		return 0;

}

int help(object me)
{
	write(@HELP
ָ���ʽ : get <��Ʒ����> [from <������>]

���ָ��������������ϻ������ڵ�ĳ����Ʒ.

HELP
    );
    return 1;
}


