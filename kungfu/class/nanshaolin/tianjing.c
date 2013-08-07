// Last Modified by Winder on May. 29 2001
// Npc: /kungfu/class/nanshaolin/tianjing.c

#include "/kungfu/class/nanshaolin/tian.h";
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
int do_yes();
string ask_me();
string ask_murenxiang();

void create()
{
	set_name("�쾵��ʦ", ({ "tianjing dashi", "tianjing", "dashi"}));
	set("long",
		"����һλ�������ɮ����һϮ��˿������ġ�����Ĳ��ߣ�\n"
		"̫��Ѩ΢͹��˫Ŀ��������\n");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 3000);
	set("max_jing", 1200);
	set("neili", 3000);
	set("max_neili", 5000);
	set("jiali",200);
	set("combat_exp", 2000000);
	set("score", 10000);

	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 200);
	set_skill("yijinjing", 200);
	set_skill("force", 200);
	set_skill("zhanzhuang-gong", 200);
	set_skill("dodge", 200);
	set_skill("yiwei-dujiang", 300);
	set_skill("cuff", 200);
	set_skill("shaolin-cuff", 300);
	set_skill("luohan-cuff", 300);
	set_skill("jingang-cuff", 300);
	set_skill("leg", 200);
	set_skill("shaolin-leg", 300);
	set_skill("ruying-leg", 300);
	set_skill("hand", 200);
	set_skill("fengyun-hand", 300);
	set_skill("boluomi-hand", 300);
	set_skill("qianye-hand", 300);
	set_skill("strike", 200);
	set_skill("weituo-strike", 300);
	set_skill("sanhua-strike", 300);
	set_skill("jingang-strike", 300);
	set_skill("boruo-strike", 300);
	set_skill("finger", 200);
	set_skill("mohe-finger", 300);
	set_skill("duoluoye-finger", 300);
	set_skill("nianhua-finger", 300);
	set_skill("one-finger", 300);
	set_skill("wuxiang-finger", 300);
	set_skill("claw", 200);
	set_skill("jimie-claw", 300);
	set_skill("eagleg-claw", 300);
	set_skill("dragon-claw", 300);
	set_skill("staff", 200);
	set_skill("pudu-staff", 300);
	set_skill("wuchang-staff", 300);
	set_skill("blade", 200);
	set_skill("cibei-blade", 300);
	set_skill("xiuluo-blade", 300);
	set_skill("club", 200);
	set_skill("weituo-club", 300);
	set_skill("zui-club", 300);
	set_skill("sword", 200);
	set_skill("damo-sword", 300);
	set_skill("fumo-sword", 300);
	set_skill("whip", 200);
	set_skill("jiujie-whip", 300);
	set_skill("xiangmo-whip", 300);
	set_skill("riyue-whip", 300);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "jingang-cuff");
	map_skill("leg", "ruying-leg");
	map_skill("hand", "boluomi-hand");
	map_skill("strike", "boruo-strike");
	map_skill("finger", "wuxiang-finger");
	map_skill("claw", "dragon-claw");
	map_skill("staff", "wuchang-staff");
	map_skill("blade", "xiuluo-blade");
	map_skill("club", "zui-club");
	map_skill("sword", "fumo-sword");
	map_skill("whip", "riyue-whip");
	map_skill("parry", "weituo-chu");

	prepare_skill("finger", "wuxiang-finger");
	
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({		
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	set("inquiry",([
		"ľ����" : (: ask_murenxiang :),
	]));

	create_family("��������", 18, "��ĦԺ����");
	setup();
	carry_object(WEAPON_DIR+"changbian")->wield();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void init()
{
	::init();
	add_action("do_yes", "yes");
	add_action("do_nod", "nod");
}

string ask_murenxiang()
{
	mapping fam;
	object me = this_player();

	if (!(fam = me->query("family")) ||
		fam["family_name"] != "��������")
		return RANK_D->query_respect(me) + "�뱾��������������֪�˻��Ӻ�̸��";
	if (me->query("muren_winner") && !wizardp(me)) 
		return RANK_D->query_respect(me) + "�����Ѿ�����ľ������ô���ɲ�Ҫ�����Ŀ������Ц��";
	if (me->query("combat_exp", 1) < 10000)
		return RANK_D->query_respect(me) + "�Ĺ������������ǲ�Ҫ��ľ����Ϊ�ã�";
//	if (me->query("score") < 10000)
//	        return RANK_D->query_respect(me) + "�������������ǲ�Ҫ��ľ����Ϊ�ã�"; 
	command("look " + this_player()->query("id"));
	command("nod");
	me->set_temp("ask_muren", 1);
	say(HIC"�쾵��ʦ����˵����ľ��������������Ϊ���յ�ȥ��֮һ�����б鲼�ֳ�������ľ�ˣ�\n������ֻ����ǰ�ߣ����޷���֮·������һ����Ҫͣ��̫��ʱ�䡣\n"NOR);
	return "��������Ѷ����͸�����(yes)��\n";
}

int do_yes()
{
	object me = this_player();

	if( !me->query_temp("ask_muren") ) return 0;
	message_vision("$nת������ƿ����ķ��񣬺���¶��һ��С�ţ�\n\n$n�������$N��һ�ƣ���$N�ƽ����ڣ�\n\n$nѸ�ٽ������ƻ�ԭλ��\n\n", me, this_object());
	me->move("/d/nanshaolin/entrance");
	me->look();
	return 1;
}

