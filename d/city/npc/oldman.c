// /d/city/npc/oldman.c
// Last Modified by winder on Aug. 5 2001

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

string *class = ({
	"dragon","phenix","kylin","elephant","lion","tiger","panther","bear","fox","wolf","dog","pig","deer","marten","cat","mouse","monkey","eagle","vulture","chicken","duck","snake","tortoise","crocodile","horse","donkey","cattle","rabbit"});
string *title = ({
	HIY"��",HIC"���",YEL"����","��","ʨ","��","��","��","��","��","��","��","¹","��","è","��","��","ӥ","��","��","Ѽ","��","��","��","��","¿","ţ","��"});
int *petstr=({30,20,25,30,25,25,20,25,12,15,12,15,10, 5, 5, 5,12,10,18, 5, 5,15, 5,18,20,18,22,10});
int *petdex=({30,30,25,10,20,20,25,12,20,20,20,10,22,20,20,18,30,25,25,20,20,15, 5,10,20,22,12,18});
int *petcon=({30,30,30,25,25,25,20,25,13,15,18,15,15,18,20,18,15,20,20,12,12,20,22,20,15,18,20,12});
int *petint=({30,30,30,12,15,15,12,12,20,12,20,10,10, 5,12,11,30,10,12,10,10, 5, 5, 8,12,10,10,12});
int *petper=({25,25,25,20,20,20,20,12,15,15,15,12,22,25,22,11,22,20,18,15,13, 8,10, 5,15,15,15,18});
int *petkar=({30,30,30,12,15,18,20,12,18,15,20,18,15,20,25,23,28,20,22,18,15,10,10, 8,12,15,15,12});
int *petcor=({30,30,30,15,20,25,25,20,12,20,18,12, 5,10,20,18,15,25,28,10,10,12,15,20,12,13,15, 5});
int *petcps=({30,30,30,25,20,20,15,20,25,12,18,15, 5, 8,10, 9,15,10,20,10,10,12,20,20,13,12,15, 5});
int *weight=({90,10,50,80,60,60,40,70,15,20,20,40,18,10,10, 8,15,20,35,10,10,18,10,30,40,30,45, 5});
int *value =({99,99,99,49,49,49,49,39,39,39,39,19,29,19, 9, 9,29,29,49, 9, 9,19, 9,39,39,29,29, 9});

int do_goumai(string arg);
void addaction(object pet);
void addaction(object pet)
{
	switch (pet->query("class"))
	{
		case "dragon"   :     //��
			pet->set("verbs",({"angel","bite","claw","rope","tail"}));break;
		case "phenix"   :     //���
			pet->set("verbs",({"claw","poke","wind"})); break;
		case "kylin"    :     //����
			pet->set("verbs",({"angel","bite","hoof","knock"}));break;
		case "elephant" :     //��
			pet->set("verbs",({"hoof","knock","snoot"})); break;
		case "lion"     :     //ʨ
			pet->set("verbs",({"bite","claw","hoof","snap"}));break;
		case "tiger"    :     //��
			pet->set("verbs",({"bite","claw","hoof","snap","tail"}));break;
		case "panther"  :     //��
			pet->set("verbs",({"bite","claw","hoof","snap"}));break;
		case "bear"     :     //��
		case "fox"      :     //��
			pet->set("verbs",({"bite","claw","hoof"})); break;
		case "wolf"     :     //��
		case "dog"      :     //��
			pet->set("verbs",({"bite","claw","hoof","snap"}));break;
		case "pig"      :     //��
			pet->set("verbs",({"bite","hoof","knock"}));break;
		case "deer"     :     //¹
		case "cattle"   :     //ţ
			pet->set("verbs",({"angel","hoof","knock"}));break;
		case "marten"   :     //��
		case "cat"      :     //è
		case "monkey"   :     //��
		case "rabbit"   :     //��
		case "mouse"    :     //��
			pet->set("verbs",({"bite","claw","hoof"})); break;
		case "eagle"    :     //ӥ
		case "vulture"  :     //��
		case "chicken"  :     //��
		case "duck"     :     //Ѽ
			pet->set("verbs",({"claw","poke","wind"})); break;
		case "snake"    :     //��
			pet->set("verbs",({"bite","rope","tail"}));break;
		case "tortise"  :     //��
			pet->set("verbs",({"bite"}));break;
		case "crocodile":     //��
			pet->set("verbs",({"bite","claw","tail"}));break;
		case "horse"    :     //��
		case "donkey"   :     //¿
			pet->set("verbs",({"bite","hoof","knock"}));break;
		default: 
			pet->set("verbs",({"bite","claw"})); break;
	}
}
void create()
{
	set_name("������ͷ", ({ "lao tou", "laotou", "oldman"}) );
	set("gender", "����" );
	set("age", 64);
	set("long","һ���뷢�԰׵����ߣ��������壬�����⡣���������Ȥ����������Ҫֻ�����������档\n");
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 400000);
	set("attitude", "friendly");
	set_skill("dodge", 120);
	set_skill("unarmed",120);
	set_skill("parry", 120);
	set_skill("force",120);
	set("inquiry", ([
		"����"  : "��Ҫ����(goumai)ʲô����뿴�������ơ�\n",
	]) );
	set("vendor_goods", ({
		FODDER_DIR+"siliao",
		FODDER_DIR+"fantuan",
		FODDER_DIR+"miantuan",
		FODDER_DIR+"roukuai",
		FODDER_DIR+"routuan",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",30);
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_goumai","goumai");
	add_action("do_return","return");
	add_action("do_lingqu","lingqu");
	add_action("do_zancun","zancun");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if( ob->query("Pet"))
	{
		say("������������Ц��������λ"+RANK_D->query_respect(ob)+"����ĳ�����������˰�����\n");
	}
	else
	{
		say("������������Ц��������λ"+RANK_D->query_respect(ob)+"��������ﰡ����\n");
	}
}
int do_goumai(string arg)
{
	object pet, gold, me = this_player(), ob = this_object();
	int num;

	if(!arg)
		return notify_fail("��ͷЦ�������𼱣����빺��ʲô������ȿ�������ơ���\n");
	if (me->query("Pet") && !wizardp(me))
	{
		command("say ��λ"+RANK_D->query_respect(me)+"������ֻ�ܻ���һֻ����������µģ��ðѾɵ��Ȼ�(return)���ҡ���\n");
		return 1;
	}
	if ( member_array(arg, class) == -1)
		return notify_fail("��ͷǸȻЦ��������ʱû�����ֳ�������뿴������ơ���\n");
	if (!wizardp(me) && me->query("combat_exp") < 2000000 &&
		(arg == "dragon" || arg == "phenix" || arg == "kylin"))
		return notify_fail("��ͷ�Ǻ�һͨ��Ц��������ľ��黹��������Щ�����\n");

	num = member_array(arg, class);
	gold = present("gold", me);
	if(!gold) return notify_fail("��ͷЦ��Ц������û������������\n");
	if((int) gold->query_amount() < value[num])
		return notify_fail("��ͷ������һ�ۣ��������ϻƽ�û��������\n");
	pet = new("/clone/misc/pet");
	pet->set("class", class[num]);
	pet->set("id", class[num]);
	pet->set("title", title[num]+NOR);
	pet->set("name", "����");
	pet->set("race", "Ұ��");
	pet->set_name("����", ({class[num], "pet"}));
	pet->set("long", "����һֻ����"+title[num]+"��\n"NOR);
	pet->set("level",1);
	pet->set("owner", me->query("id"));
	pet->set_temp("owner", me->query("id"));
	pet->set_temp("ownername", me->query("name"));
	me->set("Pet/id", class[num]);
	me->set("Pet/name", "����");

	pet->set("str", petstr[num]+random(10));
	pet->set("dex", petdex[num]+random(10));
	pet->set("con", petcon[num]+random(10));
	pet->set("int", petint[num]+random(10));
	pet->set("per", petper[num]+random(10));
	pet->set("kar", petkar[num]+random(10));
	pet->set("cor", petcor[num]+random(10));
	pet->set("cps", petcps[num]+random(10));
	pet->set("obe", 1);  //��ʼѱ����
	pet->set("age", 1);  //����
// ��������ʳ��
	pet->set("weight", weight[num]*1000);
	pet->set_weight(weight[num]*1000);
	if( random(10) > 4) pet->set("gender", "����");
	else pet->set("gender", "����");
	gold->add_amount(-value[num]);

	addaction(pet);
	pet->move(environment(me));
	message_vision("$N�ͳ�"HIR+chinese_number(value[num])+NOR"��"HIY"�ƽ�"NOR"��������һ�ң���������һֻ"+title[num]+NOR"����\n", me);
	message_vision("$N����һ��"HIY"�ƽ�"NOR"��ɫ������һ�ۣ������۵������Ȼ������������ȡ��һֻ"+title[num]+NOR"���ڵ��ϡ�\n", ob);		
	me->set("Pet/class", pet->query("class"));
	me->set("Pet/exp", pet->query("combat_exp"));
	me->set("Pet/id", pet->query("id"));
	me->set("Pet/title", pet->query("title"));
	me->set("Pet/name", pet->query("name"));
	me->set("Pet/nickname", pet->query("nickname"));
	me->set("Pet/long", pet->query("long"));
	me->set("Pet/level", pet->query("level"));
	me->set("Pet/max_jing", pet->query("max_jing"));
	me->set("Pet/eff_jing", pet->query("eff_jing"));
	me->set("Pet/jing", pet->query("jing"));
	me->set("Pet/max_qi", pet->query("max_qi"));
	me->set("Pet/eff_qi", pet->query("eff_qi"));
	me->set("Pet/qi", pet->query("qi"));
	me->set("Pet/food", pet->query("food"));
	me->set("Pet/water", pet->query("water"));

	me->set("Pet/str", pet->query("str"));
	me->set("Pet/dex", pet->query("dex"));
	me->set("Pet/con", pet->query("con"));
	me->set("Pet/int", pet->query("int"));
	me->set("Pet/per", pet->query("per"));
	me->set("Pet/kar", pet->query("kar"));
	me->set("Pet/cor", pet->query("cor"));
	me->set("Pet/cps", pet->query("cps"));
	me->set("Pet/obe", pet->query("obe"));

	if(pet->query("last_age_set"))
		pet->add("mud_age", time()-pet->query("last_age_set"));
	else pet->add("mud_age", 1);
	me->set("Pet/mud_age", pet->query("mud_age"));
	me->set("Pet/weight", pet->query("weight"));
	me->set("Pet/gender", pet->query("gender"));
	me->set("Pet/wimpy", pet->query("env/wimpy"));

	me->set("Pet/unarmed", pet->query_skill("unarmed", 1));
	me->set("Pet/dodge", pet->query_skill("dodge", 1));
	me->set("Pet/parry", pet->query_skill("parry", 1));

	return 1;
}

int do_return()
{
	object me = this_player(), *ob;
	string file, id;
	int i;

	if(!me->query("Pet"))
		return notify_fail("��ͷ�Ǻ����ˣ������û����������ɶ�������ţ���\n");
	if(me->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");
	id = me->query("id");
	ob = all_inventory(environment(me));
	for (i = 0; i < sizeof(ob); i++)
	{
		if(ob[i]->query("owner") == id && ob[i]->query("curiousness"))
		{
			break;
		}
	}
	if( i == sizeof(ob) )
		return notify_fail("��ͷ��ֵؿ�����һ�ۣ�����ĳ���û������������ô�����Ұ�����\n");
	message_vision("$Nһ�ѱ�����ϵ�$n���ݹ���̨������ͷ��\n", me, ob[i]);
	me->delete("Pet");
	destruct(ob[i]);
	me->start_busy(1);
	return 1;
}
int do_lingqu()
{
	object pet, me = this_player(), ob = this_object(), *obj;
	int i;

	if(me->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");
	if(!me->query("Pet"))
	{
		command("say ��λ"+RANK_D->query_respect(me)+"����û�ݴ�(zancun)������������ж�������ȡ����\n");
		return 1;
	}

	obj = objects();
	for (i=0; i<sizeof(obj); i++)
	{
		if(obj[i]->query("owner") == me->query("id") &&  //��ϸҲ��owner
			obj[i]->query("curiousness"))
		{
			if(environment(obj[i]) == me )
				return notify_fail(ob->name()+ "˵�����㲻����������ĳ�������ô��\n");
			else
				if(environment(obj[i]) != environment(me) )
					return notify_fail(ob->name()+"˵������ĳ�����"+(environment(obj[i])->query("outdoors") ? to_chinese(environment(obj[i])->query("outdoors")) : "����")+"��"+environment(obj[i])->query("short")+"���Ͽ�ȥ�Ұɡ�\n");
				else
					return notify_fail(ob->name()+ "˵������ĳ��ﲻ�Ǿ������Ա�ô��\n");
			return 1;
		}
	}
	pet = new("/clone/misc/pet");

	pet->set("owner", me->query("id"));
	pet->set_temp("owner", me->query("id"));
	pet->set_temp("ownername", me->query("name"));

	pet->set("class", me->query("Pet/class"));
	pet->set("id", me->query("Pet/id"));
	pet->set("title", me->query("Pet/title"));
	pet->set("name", me->query("Pet/name"));
	pet->set("nickname", me->query("Pet/nickname"));
	pet->set("race", "Ұ��");
	pet->set_name(me->query("Pet/name"), ({me->query("Pet/id"), "pet"}));
	pet->set("long", me->query("Pet/long"));
	pet->set("level", me->query("Pet/level"));

	pet->set("str", me->query("Pet/str"));
	pet->set("dex", me->query("Pet/dex"));
	pet->set("con", me->query("Pet/con"));
	pet->set("int", me->query("Pet/int"));
	pet->set("per", me->query("Pet/per"));
	pet->set("kar", me->query("Pet/kar"));
	pet->set("cor", me->query("Pet/cor"));
	pet->set("cps", me->query("Pet/cps"));
	pet->set("obe", me->query("Pet/obe"));

	pet->set("combat_exp", me->query("Pet/exp"));
	pet->set("mud_age", me->query("Pet/mud_age"));
	pet->set("age", 1+me->query("Pet/mud_age")/86400);
	pet->set("weight", me->query("Pet/weight"));
	pet->set_weight(me->query("Pet/weight"));
	pet->set("gender", me->query("Pet/gender"));
	pet->set("env/wimpy", me->query("Pet/wimpy"));

	pet->set("max_jing", me->query("Pet/max_jing"));
	pet->set("eff_jing", me->query("Pet/eff_jing"));
	pet->set("jing", me->query("Pet/jing"));
	pet->set("max_qi", me->query("Pet/max_qi"));
	pet->set("eff_qi", me->query("Pet/eff_qi"));
	pet->set("qi", me->query("Pet/qi"));
	pet->set("food", me->query("Pet/food"));
	pet->set("water", me->query("Pet/water"));

        pet->set("curiousness", 1);
	pet->set("last_age_set", time());

	pet->set_skill("unarmed", me->query("Pet/unarmed"));
	pet->set_skill("dodge", me->query("Pet/dodge"));
	pet->set_skill("parry", me->query("Pet/parry"));

	addaction(pet);

	pet->move(environment(me));
	message_vision("$N�����������ȡ��һֻ"+pet->name()+"���ڵ��ϡ�\n", ob);
	me->start_busy(1);
	return 1;
}

int do_zancun()
{
	object me = this_player(), *ob;
	string file, id;
	int i;

	if(!me->query("Pet"))
		return notify_fail("��ͷ�Ǻ����ˣ������û����������ɶ�������ţ���\n");
	if(me->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");
	id = me->query("id");
	ob = all_inventory(environment(me));
	for (i = 0; i < sizeof(ob); i++)
	{
		if(ob[i]->query("owner") == id && ob[i]->query("curiousness"))
		{
			break;
		}
	}
	if( i == sizeof(ob) )
		return notify_fail("��ͷ��ֵؿ�����һ�ۣ�����ĳ���û�������ݴ�ɶ������\n");
	if(ob[i]->query_temp("feeded"))
		return notify_fail(ob[i]->name()+"�ճ��˶�����������Ĳ������㡣\n");

	me->set("Pet/class", ob[i]->query("class"));
	me->set("Pet/exp", ob[i]->query("combat_exp"));
	me->set("Pet/id", ob[i]->query("id"));
	me->set("Pet/title", ob[i]->query("title"));
	me->set("Pet/name", ob[i]->query("name"));
	me->set("Pet/nickname", ob[i]->query("nickname"));
	me->set("Pet/long", ob[i]->query("long"));
	me->set("Pet/level", ob[i]->query("level"));
	me->set("Pet/max_jing", ob[i]->query("max_jing"));
	me->set("Pet/eff_jing", ob[i]->query("eff_jing"));
	me->set("Pet/jing", ob[i]->query("jing"));
	me->set("Pet/max_qi", ob[i]->query("max_qi"));
	me->set("Pet/eff_qi", ob[i]->query("eff_qi"));
	me->set("Pet/qi", ob[i]->query("qi"));
	me->set("Pet/food", ob[i]->query("food"));
	me->set("Pet/water", ob[i]->query("water"));

	me->set("Pet/str", ob[i]->query("str"));
	me->set("Pet/dex", ob[i]->query("dex"));
	me->set("Pet/con", ob[i]->query("con"));
	me->set("Pet/int", ob[i]->query("int"));
	me->set("Pet/per", ob[i]->query("per"));
	me->set("Pet/kar", ob[i]->query("kar"));
	me->set("Pet/cor", ob[i]->query("cor"));
	me->set("Pet/cps", ob[i]->query("cps"));
	me->set("Pet/obe", ob[i]->query("obe"));

	if(ob[i]->query("last_age_set"))
		ob[i]->add("mud_age", time()-ob[i]->query("last_age_set"));
	else ob[i]->add("mud_age", 1);
	me->set("Pet/mud_age", ob[i]->query("mud_age"));
	me->set("Pet/weight", ob[i]->query("weight"));
	me->set("Pet/gender", ob[i]->query("gender"));
	me->set("Pet/wimpy", ob[i]->query("env/wimpy"));

	me->set("Pet/unarmed", ob[i]->query_skill("unarmed", 1));
	me->set("Pet/dodge", ob[i]->query_skill("dodge", 1));
	me->set("Pet/parry", ob[i]->query_skill("parry", 1));

// ȡ������״̬
	me->delete_temp("comedby");

	message_vision("$Nһ�ѱ�����ϵ�$n���ݹ���̨����ͷ�ݴ档\n", me, ob[i]);
	destruct(ob[i]);
	me->start_busy(1);
	return 1;
}

