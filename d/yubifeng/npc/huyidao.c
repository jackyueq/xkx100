// huyidao.c
#include <ansi.h>;
inherit NPC;
string ask_book();

void create()
{
	set_name("��һ��", ({"hu yidao", "hu", "yidao"}));
	set("gender", "����");
	set("nickname", "�ɶ�����");
	set("age", 35);
	set("long","�������õ����׶�һ�ź�����Ƥ������Ũ�ף�ͷ��ȴ�ֲ�����ӣ��������ɵĶ���ͷ�ϡ�����ƽֻҪ���������µģ���ʱһ��ɱ�ˣ��������ֽ�����һ����\n");
	set("attitude", "peaceful");
        set("no_get", "1");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 17);
	
	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 190000);
	set("score", 20000);
	 
	set_skill("force", 110);             // �����ڹ�
	set_skill("hujia-daofa", 150);       // ���ҵ���	
	set_skill("blade", 120);             // ��������
	set_skill("hunyuan-yiqi", 120);      // ��Ԫһ����
	set_skill("dodge", 120);             // ��������
	set_skill("shaolin-shenfa", 120);    // ������
	set_skill("parry", 120);             // �����м�
		
	map_skill("force", "hunyuan-yiqi");
	map_skill("blade", "hujia-daofa");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "hujia-daofa");
	set("inquiry",([
		"����":     (: ask_book :),
		"���ҵ���": (: ask_book :),
	]));
	set("book_count",1);
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(BOOK_DIR"hujia-book");
}

