// /kungfu/class/baituo/ouyangfeng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

int ask_help();
int do_accept();

void create()
{
	set_name("ŷ����", ({ "ouyang", "feng" }));
	set("long", "���ǰ���ɽׯ�����ųơ���������ŷ���档\n"
		   +"����ϰ���������澭���߻���ħ���ѱ�þ�\n"
		   +"����ң�������ͷɢ����\n");
	set("title", "����ɽׯ��");
	set("gender", "����");
	set("age", 53);
	set("nickname", HIR "����" NOR);
	set("shen_type",-1);
	set("shen", -150000);
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 29);
	set("con", 30);
	set("dex", 28);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 900);
	set("max_jing", 900);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);

	set("combat_exp", 1500000);
	set("score", 200000);

	set_skill("force", 200);
	set_skill("unarmed", 170);
	set_skill("dodge", 200);
	set_skill("parry", 180);
	set_skill("hand",170);
	set_skill("training",200);
	set_skill("staff", 200);
	set_skill("hamagong", 200);
	set_skill("chanchu-bufa", 170);
	set_skill("shexing-diaoshou", 200);
	set_skill("lingshe-zhangfa", 180);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

	create_family("����ɽ��",1, "��ɽ��ʦ");
	set("chat_chance",2);
	set("chat_msg",({
		"ŷ������������������հ���ɽ�ɲ����ذԽ����ء�\n",
		"ŷ��������Ҷ�ŷ���˱��ܹ��������ɽ���۷磡\n",
		"ŷ������������ն����������ģ�\n",
	}));
	setup();
	carry_object("/d/baituo/obj/shezhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",50);
}

void init()
{
}

void attempt_apprentice(object ob)
{
	message_vision("ŷ�������$Nһ�۵������Ұ���ɽ������ҵ����ᴫ����\n", ob); 	
}


