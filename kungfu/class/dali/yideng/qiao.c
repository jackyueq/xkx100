// qiao.c �Է�

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�Է�", ({ "qiao fu", "qiao" }));
	set("title",  "������󽫾�" );
	set("long", 
"�����Ǵ������ԭ�󽫾���һ�ƴ�ʦ���Ĵ����֮һ��
��������һ���ɲ���������һ����ͷ����������ɫ��
׳����̬������������������Ǵ󽫾��а������硣��
�����ֲ����Ѷ�����ɽ�ּ��Բ񣬱ص����Ǹ�߳���
�Ƶ�ͳ����˧��\n");
	set("gender", "����");
	set("age", 45);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 35);
	set("dex", 30);

	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 10000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("cuff", 100);
        set_skill("strike", 100);
        set_skill("axe", 100);
        set_skill("finger", 100);
	set_skill("kurong-changong", 100);
        set_skill("tiannan-step", 150);
        set_skill("jinyu-quan", 150);
        set_skill("wuluo-zhang", 150);
        set_skill("duanyun-fu", 150);
        set_skill("sun-finger", 150);
	set_skill("literate", 100);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "sun-finger");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "sun-finger");
	map_skill("axe", "duanyun-fu");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jingtian" :),	
		(: perform_action, "finger.qiankun" :),			
		(: exert_function, "powerup" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

        set("inquiry", ([
                "һ�ƴ�ʦ"   : "ʦ�������˼������档\n",
                "������"     : "������ʦ�����������䡣\n",
                "������"     : "������ʦ�����������ӡ�\n",
        ]) );

        set("chat_chance", 3);
        set("chat_msg", ({
"�����ӳ�����
    ���ǳؾ㻵��Ӣ�۰��ڣ����������ཻ��������˥����Ϊ�����ƼҲ�����Ұܣ���̬
�����Ʊ�ġ�����Ҳ����ز�٣�Ҳ����ز��\n",
"�����ӳ�����
    ��������ϣ�ƾ��ң����������������ɥ�����Բԣ�ˮãã����̨�������˽���ǧ��
תͷ������������Ҳ���ó�������Ҳ���ó�����\n",
"�����ӳ�����
    ���ǳؾ㻵��Ӣ�۰��ڣ����������ཻ��������˥����Ϊ�����ƼҲ�����Ұܣ���̬
    ��������ۣ�������ŭ��ɽ�ӱ�������·���������������顣�����غ����д�������
��䶼���������ˣ����տ࣡�������տ࣡��\n",
"�����ӳ�����
    ����ɽ����������మ���β��������۹��ƽ����һéի��Ұ����������˭���˷�˭
�ɰܣ�ª�ﵥư�����ա�ƶ�������ģ��־���ģ���\n",
"�����������������ڳ�������ô
    ��������ʱ������δ���Ӯ�������������䣬������������\n",
        }) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/kungfu/class/dali/obj/axe")->wield();
	add_money("silver", 50);

	create_family("����μ�",25,"����");
}

