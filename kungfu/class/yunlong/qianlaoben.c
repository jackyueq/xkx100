// qianlaob.c
#include <ansi.h>

inherit NPC;
inherit F_BANKER;
int ask_weiwang();

void create()
{
	set_name("Ǯ�ϱ�", ({"qian laoben", "qian", "laoben"}));
	set("title", HIR "��ػ�"HIG"��ľ��"NOR"����");
	set("gender", "����");
	set("age", 34);

	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);

	set("qi", 800); 
	set("max_qi", 800);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 800); 
	set("max_neili", 800);
	set("jiali", 20);
	set("shen", 0);

	set("no_get", 1);
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 5);
	set("chat_msg", ({
		"Ǯ�ϱ�˵�����ҽ�Ǯ�ϱ���������Ϊ���������ϱ�Ҳ���ˡ�\n",
		"Ǯ�ϱ�Ц��˵�����ڱ����Ǯ��Ϣ���ٰٷ�֮һ���͹���ֻ�ܴ�ɡ�\n",
		"Ǯ�ϱ�˵��ֻ�жԱ��ɵ����Ҳ���ô�������Ա���˰����ߺ�......\n",
		"Ǯ�ϱ�ͻȻ˵��: ������������Ҫ������ֵ�ߴ��кô�����\n",
		"Ǯ�ϱ�ͻȻ˵�����˷ֿ�һ��ʫ�����Ϻ�Ӣ����֪��\n",
	}));
	set("inquiry", ([
		"��Ϣ" : "��Ҫ��Ϣ����ᣡ\n",
		"�½���" : "����ܶ�����û��ô���ס�\n",
		"��ػ�" : "ֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"����" : "ֻҪ��������ػᣬ��������и�λ����ѧ���ա�\n",
		"���" : "ֻҪ��������ػᣬ��������и�λ����ѧ���ա�\n",
		"����" : (: ask_weiwang :),
		"��������" : (: ask_weiwang :),
	]) );

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 5);
}

void init()
{
	add_action("do_check", "check");
	add_action("do_check", "chazhang");
	add_action("do_convert", "convert");
	add_action("do_convert", "duihuan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
	delete_temp("busy");
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
	say( "Ǯ�ϱ�˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
	say("Ǯ�ϱ���˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
	return 1;
}
