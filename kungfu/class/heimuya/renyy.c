// renyy.c
#include <ansi.h>;
inherit NPC;
string ask_ling();
int ask_tuijiao();

void create()
{
	set_name("��ӯӯ", ({ "ren yingying","ren","ying"}) );
	set("gender", "Ů��" );
	set("long", "����ë��������ò�������������ף�����ʮ�߰�����͡�");
	set("age", 18);
	set("shen_type", 1);
	set("combat_exp", 500000);
	set("env/wimpy", 40);
	set("per", 30);
	set("str", 16);
	set("dex", 27);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	
	set("max_qi", 3000);
	set("max_jing", 2000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 200);
	set("combat_exp", 1200000);

	set_skill("luteplaying", 200);      // ��������
	set_skill("literate", 100);         // ����ʶ��
	set_skill("force", 180);            // �����ڹ�
	set_skill("dodge", 180);            // ��������
	set_skill("unarmed", 180);          // ����ȭ��
	set_skill("parry", 180);            // �����м�
	set_skill("dagger", 180);           // �����̷�
        set_skill("shigu-bifa", 180);       // ʯ�Ĵ�Ѩ�ʷ�
	set_skill("piaoyibu", 180);         // Ʈ�ݲ���
	set_skill("kuihua-xinfa", 180);     // �����ķ�
	set_skill("xixing-dafa", 50);       // ���Ǵ�
	set_skill("changquan", 180);        // ̫�泤ȭ

	map_skill("force", "xixing-dafa");
	map_skill("dagger", "shigu-bifa");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "shigu-bifa");

	set("chat_chance",60);
    	set("chat_msg",({
	"��ӯӯ˵���������ܰ�������Ӹ�������̫лл����.............\n",
	"��ӯӯ����˵�����������������ˣ�ֻ����ע��Ҫ���ú������ˡ����պ��������Ҹ��ģ���Ҳ������������������ҡ����ҡ�������������һ��������������\n",
	"��ӯӯ˵����Ҳ��֪����˼�û�����������漱������......\n",
	}) );
       
	set("party/party_name", HIB"�������"NOR);
	set("party/rank", MAG"ʥ��"NOR);
	create_family("��ľ��", 8, "����");
	set("inquiry",([
		"�����"  : (: ask_ling :),
		"�˽�"    : (: ask_tuijiao :),
		"tuijiao" : (: ask_tuijiao :),
	]) );
	set_temp("letter",1);
	setup();
	carry_object(CLOTH_DIR"female-cloth")->wear();
	carry_object(CLOTH_DIR"female-shoe")->wear();
	carry_object(WEAPON_DIR"dagger")->wield();
	carry_object("/d/heimuya/npc/obj/letter");
}

string ask_ling()
{
	object me=this_player();
	object obn;

	message_vision("��ӯӯ˵����ȥ���ϻ�ɽһȥ���������ţ������������Ұ�......\n", me );
	if(query_temp("letter")==0)
	{
		message_vision("��ӯӯ��˵������λ"+ RANK_D->query_respect(me)+"�����Ѿ��������ȥѰ���ˣ�Ҳ��֪����ô���ˡ�\n",me);
		return "";
	}
	message_vision("��ӯӯ��˵������λ"+ RANK_D->query_respect(me)+"�����������ţ���Ҫ���ҵ�����壬�Ͱ��Ž��������������׵ġ�\n" , me);
	obn=new("/d/heimuya/npc/obj/letter");
	obn->move(me);
	set_temp("letter",0);
   
	return ("����ŷ��㽻������塣\n");
}
int ask_tuijiao()
{
        object ob;
        ob=this_player();

        if(ob->query("party/party_name") != HIB"�������"NOR)
        {
		message_vision("ӯӯǳǳһЦ����$N˵�����㻹û����������أ������˽̣�\n",ob);
		return 1;
        }
        if(ob->query("family/family_name") == "��ľ��" )
        {
	message_vision("ӯӯ̧��������$N˵�������Ѿ��Ǻ�ľ�µ��ӣ�������˽̣�\n", ob);
                return 1;
        }

        command("look "+ob->query("id"));
        command("sigh ");
        command("nod ");
        ob->delete("party");
        return 1;
}

void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"�������"NOR)
	{
		command("say ��ֻ����̵��ӣ������Ĵ��ó������ȥ��\n");
		return;
	}
	if ((int)ob->query_skill("kuihua-xinfa", 1) < 60)
	{
		command("say ��ѧ�ҽ̹������ڹ��ϣ�" + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö��µ㹦��");
		return;
	}
	command("say �ðɣ���������������ˡ�");
	command("recruit " + ob->query("id"));
}

