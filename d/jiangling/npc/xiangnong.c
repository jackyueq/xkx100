//Edited by fandog, 02/13/2000

inherit NPC;

void create ()
{
	set_name("��ũ", ({"xiang nong", "nong"}));
	set("long", "һ������ũ�񣬺���������ӣ�����ϴ��˿���������ƺ���\n");
	set("gender", "����");
	set("age", 24);
	set("combat_exp", 500);
	set("str", 24);
	set("int", 15);
	set("dex", 18);
	set("con", 22);
	set("per", 20);
  
	setup();
	carry_object("/clone/cloth/cloth")->wear();
        carry_object("/d/jiangling/obj/chutou")->wield(); 
}


