// niu.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("ţ", ({ "niu" }));
	set("title", "��ʿ");
	set("shen_type", 1);

	set("gender", "����" );
	set("long", @LONG
�����ǵ���̨��ũҵ��ҵ���࣬����ʱͶ�����̣�׷���Ž�������
�������꣬�����˺պ�ս�����������˺���������ͷ�塣
LONG);
	set("nickname", HIG"ũҵƵ�����Ρ���ҵ��ҵƵ������"NOR);
	set("age", 30);
	set("per", 30);
	set("attitude", "friendly");		
        set("no_get", "1");
	set("env/no_teach", "1");

	set("inquiry", ([
                 "yoyo": "����̨���������ڵ���̨������Ҫ�������\n",
           "singleblue": "ϸ�첲���������ҵ��޵д����\n",
                  "lip": "�Ǹ���������ͷ�����ڴ�����mm�ء�",
               "fandog": "�����󹷹�����������Ĵ峤��",
                  "niu": "��ʲô�ʣ�û��������˧��ţ��",
	]));   
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1400);
	set("max_jing", 700);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 150);

	set("combat_exp", 3000000);
	set_skill("force", 250);
	set_skill("jiuyang-shengong", 250);
	set_skill("dodge", 250);
	set_skill("qiankun-danuoyi", 250);
	set_skill("cuff", 250);
	set_skill("qishang-quan", 250);
	set_skill("parry", 250);
	set_skill("sword", 250);
	set_skill("shenghuo-ling", 250);
	set_skill("taoism", 150);
	set_skill("literate", 300);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "qiankun-danuoyi");
	map_skill("cuff", "qishang-quan");
	map_skill("parry", "qishang-quan");
	map_skill("sword", "shenghuo-ling");
	setup();

	carry_object(CLOTH_DIR"niupi-dayi")->wear();
        carry_object(CLOTH_DIR"niupi-xue")->wear();
}