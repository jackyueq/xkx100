// Feb. 6, 1999 by Winder
// jinshe.c �����ɾ�
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void dest(object ob);
string ask_skill1(object me,string arg);
string ask_skill2(object me,string arg);
string ask_skill3(object me,string arg);
void create()
{
	set_name("��ѩ��", ({"xia xueyi", "xia", "xueyi"}));
	set("nickname", HIY"�����ɾ�"NOR);
	set("gender", "����");
	set("age", 25);
	set("long", 
		"�������˳ơ������ɾ�����һ���ֽܡ�����ѩ�ˡ�\n"
		"������ȫƾ�ö�ʱ��ʱа���˵��Ƕ����������ò�������\n"
		"��˵���������ܲң���Ҳ���ƫ��������\n"
		"���������������˵��ˣ���ɫ���ѿ���\n");
 	set("attitude", "peaceful");
	
	set("str", 100);
	set("int", 20);
	set("con", 30);
	set("dex", 25);
	set("chat_chance", 15);
	set("chat_msg", ({
		"��ѩ��ͻȻ��ݺݵ�˵�����Ƕ����㵽��ΪʲôҪ���ң���\n",
		"��ѩ�����з·�Ҫ���������\n",
                "ͻȻ����ѩ�ˡ��ۡ���һ�����³�һ��ڴ��ڵ�Ѫ��\n",
	}));
	set("inquiry", ([
		"����": "��....��..... \n",
		"������" 	:	(: ask_skill1 :),
		"���ǲ���":	(: ask_skill2 :),
		"��������":	(: ask_skill3 :),
	]));
	set("qi", 10000);
	set("max_qi", 10000);
	set("jing", 5000);
	set("max_jing", 5000);
	set("neili", 9000);
	set("max_neili", 9000);
	set("jiali", 100);
	set("no_get",1);
	
	set("combat_exp", 10000000);
	 
	set_skill("force", 200);		// �����ڹ�
	set_skill("huntian-qigong", 200);	// ��������
	set_skill("unarmed", 220);		// ����ȭ��
	set_skill("dodge", 200);		// ��������
	set_skill("parry", 200);		// �����м�
        set_skill("sword", 200);                // ��������
        set_skill("jinshe-jian",200);           // ���߽���
	
	map_skill("force", "huntian-qigong");
	map_skill("sword", "jinshe-jian");
	map_skill("parry", "jinshe-jian");
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
int accept_object(object who, object ob)
{
	object obn;
	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("��û�����������\n");
	if (  (string)ob->query("id") != "wen shoupa")
		    return notify_fail("��ѩ�˲���Ҫ���������\n");
         write(HIY "��ѩ�˽ӹ������������س���ͻȻ����Ȼ���¡� \n" NOR);
         write(HIR "��ѩ���૵����Ƕ�������֪��������⣬��ʵ��������ģ���Ҳ���ں��ġ�\n" NOR);         
         write(HIY "��ѩ��ת��ͷ������˵���Ҹ�������л���أ�\n" NOR);
         write(HIY "����ת��ȥ����Ĭ���������˼����ʲô��\n" NOR);
         write(HIY "��ѩ��ͻȻ�����˺ܴ�����Ƶض���˵���ҿ�\n" NOR);
         write(HIY "��Ҳ���������ˣ������������ұ�����Ѫ�ġ�������ܸ����\n" NOR);
         write(HIY "������������˵�Ѿ�û��ʲô���ˣ������ȥ�ɡ�\n" NOR);
         write(HIY "��ѩ��̾�˿����������ǳ�������Ҳ�ã���������Ҳ�ã�������ΪҲ�ã�ͨͨ�����޹ء�\n" NOR);
         write(HIY "��ѩ�˻��˻��֣����ˣ���������ˡ�\n" NOR);
         obn = new("/clone/book/jinshe2");
         obn->move(who);
         obn = new("/clone/book/jinshe3");
         obn->move(who);
         write(HIR "��ѩ�˻��װ���ǽ�ϵ�һ�����أ�ֻ����¡¡�������죬ʯ��֮��¶��һ���ķ��Ķ�������\n"NOR);
         "/d/shiliang/jinshedong"->set("exits/east","/d/shiliang/jinshedong1");
         destruct(ob);
         return 1;
}
void dest(object ob)
{
    destruct(ob);
}
string ask_skill1(object me,string arg)
{
	return teach_perform(this_player(),this_object(),([
		"perform"	: "suo",	//pfm�Ĵ���
		"name"		: "������",	//pfm������
		"sk1"		: "jinshe-jian",//��Ҫ���书��id
		"lv1"		: 100,		//��Ҫ���书�ĵȼ�
		"sk2"		: "sword",	//��Ҫ�书sk2��id
		"lv2"		: 100,		//��Ҫ�书sk2 �ĵȼ�
		"neili"		: 300,		//��Ҫ�����ڹ��ȼ�
		"free"		: 1, 		//free=1����Ҫͬһ����
		"msg1"		: "$N����һЦ��Ҫѧ��ʵ���в����ѣ������˶��Գ�����С�\n"+
				"���ҽ��߽�����������У�����Ҫּ�����⾳��������ʽ��\n"+
				"$n����$N��ָ������Ȼ����",
		"msg2"		: "���ˣ����Լ�������ϰ�ɡ�",
		]));
}
string ask_skill2(object me,string arg)
{
	return teach_perform(this_player(),this_object(),([
		"perform"	: "fugu",	//pfm�Ĵ���
		"name"		: "���ǲ���",	//pfm������
		"sk1"		: "jinshe-zhang",//��Ҫ���书��id
		"lv1"		: 100,		//��Ҫ���书�ĵȼ�
		"sk2"		: "strike",	//��Ҫ�书sk2��id
		"lv2"		: 100,		//��Ҫ�书sk2 �ĵȼ�
		"neili"		: 300,		//��Ҫ�����ڹ��ȼ�
		"free"		: 1, 		//free=1����Ҫͬһ����
		]));
}
string ask_skill3(object me,string arg)
{
return teach_perform(this_player(),this_object(),([
		"perform" 	: "tuwu",	//pfm�Ĵ���
		"name"		: "��������",	//pfm������
		"sk1"		: "jinshe-zhui",//��Ҫ���书��id
		"lv1"		: 100,		//��Ҫ���书�ĵȼ�
		"sk2"		: "throwing",	//��Ҫ�书sk2��id
		"lv2"		: 100,		//��Ҫ�书sk2 �ĵȼ�
		"force"		: 100,		//��Ҫ�����ڹ��ȼ�
		"neili"		: 300,		//��Ҫ�����������
		"free"		: 1, 		//free=1����Ҫͬһ����
		]));
}
