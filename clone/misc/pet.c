// /clone/misc/pet.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>;
#include <combat.h>;
#include <skill.h>;
inherit NPC;

string *player_name = ({
        "���",
        "����",
        "����",
        "��",
        "��־��",
        "��־",
        "Ϻ�����",
});

void create()
{
	set_name("����", ({"pet"}));
	set("race", "Ұ��");
	set("age", 1);
	set("mud_age", 1);
	set("combat_exp", 100);
	set("limbs", ({ "ͷ��","����","ǰ��","��","ǰצ","����","β��" }) );
	set("verbs", ({ "bite", "claw"}));

	set("ride/msg", "��");
	set("ride/dodge", 5);
	set("curiousness", 1);    // ��ѧ�ġ�����ѧϰ������
	set("owner","mudlib");
	set_temp("owner","mudlib");
	set_temp("apply/attack", 5);
	set_temp("apply/armor", 5);
	setup();
}

void init()
{
	if(this_object()->query_temp("owner") == this_player()->query("id"))
	{
		add_action("do_shape", "shape");
		add_action("do_modify", "modify");
		add_action("do_xunlian", "xunlian");
//		add_action("do_order", "order");
//		add_action("do_command", "command");
	}
}
void unconcious()
{
	die();
}
void die()
{
	object *obj;
	int i, exp = query("combat_exp");

	message("channel:rumor", HIM"��ҥ�ԡ�ĳ�ˣ���˵"+query_temp("ownername")+HIM"��"+name()+HIM"���ˣ��ȼ��½��ˡ����ǿ�ϧ��\n"NOR, users());

	obj = objects();
	for (i=0; i<sizeof(obj); i++)
	{
		if(obj[i]->query("id") == this_object()->query("owner") )
		{
			obj[i]->delete_temp("comedby");
			obj[i]->set("Pet/exp", exp/10 * 9);
			if(obj[i]->query("Pet/level") >= 0)
				obj[i]->add("Pet/level", -1);
			if(obj[i]->query("Pet/obe") > 0)
				obj[i]->add("Pet/obe", -1);
			if(obj[i]->query("Pet/unarmed") > 0)
				obj[i]->add("Pet/unarmed", -1);
			if(obj[i]->query("Pet/parry") > 0)
				obj[i]->add("Pet/parry", -1);
			if(obj[i]->query("Pet/dodge") > 0)
				obj[i]->add("Pet/dodge", -1);
			if(obj[i]->query("Pet/level") <= 0)
			  obj[i]->delete("Pet");
			break;		
		}
	}

	::die();
}
int do_modify(string arg)
{
	string item, msg;
	int i;
	object me = this_player();

	if(!arg || sscanf(arg,"%s %s", item, msg) != 2)
		return notify_fail("�������modify ���� ����\n\n\t�����б�

                    ����         name
                    �º�         nick
                    ϸ������     long
                    ����ϵ��     wimpy\n\n");
	if(me->query("jing") < 20)
		return notify_fail("��ľ������㣬��ʱû���޸ĳ��\n");
	if(item == "wimpy")
	{
		set("env/wimpy", atoi(msg));
		write("�趨��������ϵ���ɹ���\n");
		return 1;
	}
	msg = replace_string(msg, "$BLK$", BLK);
	msg = replace_string(msg, "$RED$", RED);
	msg = replace_string(msg, "$GRN$", GRN);
	msg = replace_string(msg, "$YEL$", YEL);
	msg = replace_string(msg, "$BLU$", BLU);
	msg = replace_string(msg, "$MAG$", MAG);
	msg = replace_string(msg, "$CYN$", CYN);
	msg = replace_string(msg, "$WHT$", WHT);
	msg = replace_string(msg, "$HIR$", HIR);
	msg = replace_string(msg, "$HIG$", HIG);
	msg = replace_string(msg, "$HIY$", HIY);
	msg = replace_string(msg, "$HIB$", HIB);
	msg = replace_string(msg, "$HIM$", HIM);
	msg = replace_string(msg, "$HIC$", HIC);
	msg = replace_string(msg, "$HIW$", HIW);
	msg = replace_string(msg, "$NOR$", NOR);

	if(item != "nick")
	{
		if(CHINESE_D->check_control(msg))
			return notify_fail("���������в����п��Ʒ���\n");
		if(!CHINESE_D->check_chinese(msg))
			return notify_fail("�������������ġ�\n");
	}
	if(CHINESE_D->check_space(msg))
		return notify_fail("�����в��ܺ��ո�\n");
	if(CHINESE_D->check_return(msg))
		return notify_fail("���������в��ܺ��س�����\n");
	me->receive_damage("jing", 10);
	switch(item)
	{
		case "name" :
			if(CHINESE_D->check_length(msg) > 10)
				return notify_fail("���ﰮ������̫����\n");
			for(i = 0; i < sizeof(player_name); i++)
			{
				if(strsrch(msg, player_name[i]) >= 0)
					return notify_fail("�����ʵĳ��ﰮ�ơ�\n");
			}
			set("name", msg+query("title")+NOR);
			me->set("Pet/name", msg+query("title")+NOR);
			write("���ﰮ���趨�ɹ���\n");
			return 1;
		case "nick" :
			if(CHINESE_D->check_length(msg) > 20)
				return notify_fail("����º�����̫����\n");
			set("nickname",msg+NOR);
			write("����º��趨�ɹ���\n");
			return 1;
		case "long":
			if(CHINESE_D->check_length(msg) > 100)
				return notify_fail("����ϸ������̫����\n"); 
			set("long",msg+"\n"+NOR);
			write("����ϸ���趨�ɹ���\n");
			return 1;
	}
	return notify_fail("��Ҫ�޸�ʲô��\n");
}
int do_xunlian(string arg)
{
	object me = this_player(), pet = this_object();
	int jing_cost, amount, exp, myskill, itskill;

	if(!arg || arg == "")
		return notify_fail("��Ҫѵ������ʲô�����أ�\n");
	if(!myskill = me->query_skill(arg,1))
		return notify_fail("���������󻹲����أ�\n");
	if(arg != "unarmed" && arg != "dodge" && arg != "parry")
		return notify_fail("��ѧ��������ܵģ�\n");
	itskill = query_skill(arg, 1);
	if(myskill <= itskill)
		return notify_fail( name()+"�Գ�Ц��Ŀ�������㣺�㻹û��ţ�أ�����ң���\n");
	if(me->is_busy())
		return notify_fail("��Ķ�����û����ɣ����̵ܽ����\n");
	if(me->is_fighting() )
		return notify_fail("���Ѿ���ս�����ˣ�����̵����\n");
	if(pet->is_busy())
		return notify_fail("���Ķ�����û����ɣ�����ѧϰ��\n");
	if(pet->is_fighting() )
		return notify_fail("���Ѿ���ս�����ˣ�����ѧϰ��\n");
	if((int)me->query("potential")-(int)me->query("learned_points") < 1)
		return notify_fail("���Ǳ�ܲ�����\n");
	jing_cost = (int) query_int();
	if((int)me->query("jing") < jing_cost)
		return notify_fail("����Ȼ̫���ˣ�û�а취�����̣�\n");
	me->receive_damage("jing",jing_cost);
	amount = (int)((me->query("int") + query("int"))/3);
	message_vision(sprintf("$N�����䷳�ؽ�$n��%s����\n",to_chinese(arg)), me, pet);
	if(random(100) > query("obe") )
	{
		message_vision("$N�ܲ���Ը�غ���һ����\n", pet);
		return 1;
	}
	else 
	{
		exp = pet->query("combat_exp");
		if( itskill * itskill * itskill / 10 < exp)
		{
			pet->improve_skill(arg, amount);
			pet->add("combat_exp", random(5));
			me->add("learned_points", 1);
			message_vision(sprintf("$N�ƺ����ѧ����һЩ��%s����\n", to_chinese(arg)), pet);
		}
		else
			message_vision(sprintf("���ھ������ޣ�$N�ƺ�������������ġ�%s����\n", to_chinese(arg)), pet);
	}
	return 1;

}
string status_color(int current, int max)
{
	int percent;

	if( max>0 ) percent = current * 100 / max;
	else percent = 100;
	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}
int do_shape(string arg)
{
	mapping my;
	string shape;
	int at_pt,pa_pt,do_pt;
	my = query_entire_dbase();

	printf(HIC"��"HIY"������������������������������������������������������������"HIC"��\n"NOR);
	printf("���ˣ� %s\t\t\t������ %s\n"NOR, my["owner"], this_object()->query_temp("ownername"));
	printf("���䣺 %d\t���ࣺ %s\t���ƣ� %s\t�ºţ� %s\n"NOR, my["age"], my["title"], my["name"], my["nickname"]);
	printf("���ǣ� %d\t���ʣ� %d\t�ٶȣ� %d\t������ %d\n",query_int(),query_con(),query_dex(),query_str());
	printf("��̬�� %d\t���ԣ� %d\tð�գ� %d\t���ƣ� %d\n",query_per(),query_kar(),query_cor(), query_cps());
	printf("ѱ���� "HIM"%d"NOR"\tɱ���� "HIR"%d"NOR"\t���飺 "HIG"%d"NOR "\t������ "HIC"%d\n"NOR, query_obe(), my["shen"], my["combat_exp"], this_object()->query("env/wimpy"));
	at_pt= COMBAT_D->skill_power(this_object(),"unarmed",SKILL_USAGE_ATTACK);
	pa_pt= COMBAT_D->skill_power(this_object(),"parry",SKILL_USAGE_DEFENSE);
	do_pt= COMBAT_D->skill_power(this_object(),"dodge",SKILL_USAGE_DEFENSE);
	printf("������ "HIY"%d"NOR"\t������ "HIC"%d\t"NOR"ʳ� %s%3d/ %3d\t"NOR"��ˮ�� %s%3d/ %3d\n"NOR,
		at_pt+1, pa_pt/2+do_pt/2+1,
		status_color(my["food"], this_object()->max_food_capacity()),
		my["food"], this_object()->max_food_capacity(),
		status_color(my["water"], this_object()->max_water_capacity()),
		my["water"], this_object()->max_water_capacity());
	printf("������%s%3d/ %3d %s(%3d%%)\t\t"NOR"��Ѫ��%s%3d/ %3d %s(%3d%%)\n\n"NOR, status_color(my["jing"],my["eff_jing"]),my["jing"],my["eff_jing"], status_color(my["eff_jing"],my["max_jing"]),my["eff_jing"]*100/my["max_jing"], status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"], status_color(my["eff_qi"], my["max_qi"]), my["eff_qi"] * 100 / my["max_qi"] );		
	printf(HIC"��"HIY"������������������������������������������������������������"HIC"��\n"NOR);
	printf("/cmds/skill/skills"->pet_skill(this_object()));
	printf(HIC"��"HIY"������������������������������������������������������������"HIC"��\n"NOR);
	return 1;
}
string *cmds_exclude=({		  //���뱻��ֹ��cmds
	"wiz",
	"sys",
	"go",
});				
int do_command(string arg)
{
	int err, i, j;
	string id, cmd;
	string *cmds;
	object who = this_player();
	object me= this_object();

	if( !arg || sscanf(arg, "%s to %s", id, cmd)!=2)
		return notify_fail("��Ҫ����ʲô��ʲô��\n");
	if(id!=(string)me->query("id")) return 0;
	if(who->query("id")!=me->query_temp("owner"))
		return notify_fail("���"+me->query("name")+"�����˼��䣬�������������㡣\n");
	tell_object(who,"������" +me->name() + "ȥ: " + cmd + "\n");	
	cmds = explode(cmd," ");
	for(i=0;i< sizeof(cmds_exclude);i++)
		if (!strcmp(cmds[0],cmds_exclude[i]))
			j = i;
	if(!strcmp(cmds[0],cmds_exclude[j]))	
		return notify_fail("����ҷ��˼���ָ�"+me->query("name")+"�����޹��Ĵ��۾�@_@�����㣺���Ҳ���Ү....��\n");	
//	err=me->command(cmd);
	return me->force_me(cmd);
/*
	if (!err )
		return notify_fail("����ҷ��˼���ָ�"+me->query("name")+"�����޹��Ĵ��۾�@_@�����㣺���Ҳ���Ү....��\n");
	return 1;
*/
}
int do_order(string arg)
{
	int obedience;
	object me = this_player();

	if(me->query("jing") < 20)
		return notify_fail("��ľ������㣬��ʱû��ʹ�����\n");
	me->receive_damage("jing", 5);
	obedience = query("obe");
	if(random(100) < obedience )
		command("emote " + arg);
	else command("emote �ܲ���Ը�غ���һ����");
	return 1;
}
