// qqren.c ��ǧ��
// Last Modified by winder on Nov. 17 2001

inherit NPC;
int ask_qiubai();
inherit F_MASTER;
inherit F_MANAGER;

void create()
{
	set_name("��ǧ��", ({ "qiu qianren", "qiu", "qianren", "ren"}));
	set("nickname", "����ˮ��Ư");
	set("long", "����������������ư�İ���-����ˮ��Ư��ǧ��\n"
	"����һ��������ͷ�����Ƹ���������ֻ���һ�Ѵ����ȡ�\n");
	set("gender", "����");
	set("age", 60);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 28);
	set("dex", 35);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 200);
	set("combat_exp", 3000000);
	set("score", 400000);

	set_skill("force", 160);
	set_skill("guiyuan-tunafa", 160);
	set_skill("dodge", 160);
	set_skill("shuishangpiao", 220);
	set_skill("spear", 160);
	set_skill("tiexue-qiang", 220);
	set_skill("strike", 180);
	set_skill("zhusha-zhang", 220);
	set_skill("tiezhang-zhangfa", 220);
	set_skill("parry", 160);
	set_skill("literate", 100);

	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("strike", "tiezhang-zhangfa");
	map_skill("spear", "tiexue-qiang");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");

	set("no_get",1);
	set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		(: perform_action, "strike.zhangdao" :),
		(: perform_action, "strike.tianlei" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

	create_family("���ư�", 14, "����");

	set("inquiry", ([
		"name" : "�Ϸ���ǡ�����ˮ��Ư����ǧ�������Ϸ�������ʲô��ô��\n",
		"here" : "����������ư����̳���ڣ�����û�£���Ҫ�Ĵ����ߣ�����ɱ��֮��������\n",
		"�Ϲٽ���" : (: ask_qiubai :),
	]));
	setup();
	carry_object(__DIR__"obj/yellowcloth")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object me)
{
	if ((int)me->query("shen") > -10000)
	{
		command("hehe");
		command("say ����ǧ��ɲ����Ĵ����������ͽ�ܡ�");
		return;
	}
	command("say �ðɣ��Ҿ��������ˡ�ϣ������������񹦣���֮������");
	command("recruit " + me->query("id"));
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		add("apprentice_available", -1);
}
int ask_qiubai()
{
	say("������ʦ��������ʮ�����������ȹ�����֮�����ж�ͼ������ȫ\n"
	"���书�������ܡ���ϧʮ��ǰ�����ں�������Χ������������\n");
	return 1;
}

