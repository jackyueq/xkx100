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
		return notify_fail("你要捡起什么东西？\n");

	if (me->is_busy())
		return notify_fail("你上一个动作还没有完成！\n");

	if (sscanf(arg, "%s from %s", arg, from) == 2) {
		env = present(from, me);
		if (!env)
			env = present(from, environment(me));
			
		if (!env)
			return notify_fail("你找不到 " + from + " 这样东西。\n");
			
		if ((env->query("no_get_from") || living(env))
			&& (wiz_level(me) <= wiz_level(env)))
			return notify_fail("你的巫师等级必须比对方高，才能搜身。\n");
	} else
		env = environment(me);

	if (sscanf(arg, "%d %s", amount, item) == 2) {
		if (!objectp(obj = present(item, env)))
			return notify_fail("这里没有这样东西。\n");
			
		if (!obj->query_amount())
			return notify_fail(obj->name() + "不能被分开拿走。\n");
			
		if (amount < 1)
			return notify_fail("东西的个数至少是一个。\n");

		if (amount > obj->query_amount())
			return notify_fail("这里没有那麽多的" + obj->name() + "。\n");
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
			return notify_fail("你还在战斗中！只能一次拿一样。\n");
			
		if (!env->query_max_encumbrance())
			return notify_fail("那不是容器。\n");
			
        	if (env->is_tree())
        		return notify_fail("这是给新手活命用的，还是不要太贪心了吧n");

		inv = all_inventory(env);
		if (!sizeof(inv)) {
        		if (env->is_tree())
                		return notify_fail("树上什么也没有了。\n");
			return notify_fail("那里面没有任何东西。\n");
        	}

		for (i = 0; i < sizeof(inv); i ++) {
			if (inv[i]->is_character() || inv[i]->query("no_get"))
				continue;
			do_get(me, inv[i]);
		}
		write("捡好了。\n");
		return 1;
	}

	if (!objectp(obj = present(arg, env)) || living(obj))
		return notify_fail("你附近没有这样东西。\n");

	if (obj->query("no_get"))
		return notify_fail("这个东西拿不起来。\n");

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
					   "正守在" + obj->name() +
					   "一旁，防止任何人拿走。\n");
	}

	if (obj->query("equipped"))
		equipped = 1;

	if (obj->move(me)) {

		if (me->is_fighting())
			me->start_busy(1);

		if (obj->is_character())
			message_vision("$N将$n扶了起来背在背上。\n", me, obj);
		else {
			msg += "$N";
			if (old_env == environment(me))
				msg += "捡起";
			else if (old_env->is_character())
				msg += "从" + old_env->name() + "身上" + (equipped?"除下":"搜出"); 
			else if (old_env->is_tree())
				msg += "从" + old_env->name() + "摘下";
			else
				msg += "从" + old_env->name() + "拿出";

			msg += "一" + obj->query("unit");
			
			msg += "$n。\n";

			message_vision(msg, me, obj);
			
			// 原先写法可读性较差，改为上面的写法。
			// Added by Constant Jan 6 2001
/*
			message_vision(sprintf("$N%s一%s$n。\n",
					old_env==environment(me)?
						"捡起"
					:(old_env->is_character()?
					  	"从" + old_env->name() + "身上" + (equipped?"除下":"搜出")
					:(old_env->is_tree()?
					  	"从" + old_env->name() + "上摘下"
					:"从" + old_env->name() + "中拿出")),
					obj->query("unit")), 
					me, obj);
*/
		}
		
		// 增加任务物品的信息显示。
		// Added by Constant Jan 6 2001		
		if (quest = obj->query("dynamic_quest")) {
			if (!objectp(owner = find_object(quest["owner_name"])))
				owner = load_object(quest["owner_name"]);

			message("system", HIY"【风闻】"HIG 
						+ me->query("name") 
						+ "找到" 
						+ owner->query("name")
						+ HIG"的"NOR + obj->query("name") + HIG"啦！\n"NOR, 
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
指令格式 : get <物品名称> [from <容器名>]

这个指令可以让你捡起地上或容器内的某样物品.

HELP
    );
    return 1;
}


