// Feb. 6, 1999 by Winder
inherit NPC;
string inquiry_afeng();
void create()
{
	set_name("����", ({ "a tu","a","tu"}) );
	set("gender", "����" );
	set("age", 18);
	set("long", "����һ��Ӣ�����������ˡ�\n");
	set("shen_type", 1);
	set("combat_exp", 500);
	set("str", 16);
	set("dex", 17);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	set("chat_chance",1);
	set("chat_msg",({
	    "����һ��ɨ��һ��ҡ��ͷ��\n",
	    "�������������˵����һֱϲ�����������ô��������أ�\n",
	    "����ͻȻ�������Դ������ˣ��Ҹ���д����ɣ�\n"
	}) );
	set("inquiry",([
		"����" : (: inquiry_afeng :),
	]) );
	set_temp("qingshu",1);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
string inquiry_afeng()
{
 object me=this_player();
 object obn;
 message_vision("����˵������λ"+ RANK_D->query_respect(me)+"���ҿ���Ҳ����������,�ҾͲ�������Ȧ���ˣ����ܰ�����Ž���������\n", me );
 if(query_temp("qingshu")==0)
 {  message_vision("������˵������λ"+ RANK_D->query_respect(me)+"�����Ѿ����˰��Ҵ��ˣ�Ҳ��֪������������Σ���.....\n",me);
   return "";
 }
   message_vision("������˵������λ"+ RANK_D->query_respect(me)+"���������з���д��������ҹ�����飬�鷳����,�Һ�������Ҹ����и����ˡ�\n" , me);
   obn=new("/d/shiliang/npc/obj/qingshu");
   obn->move(me);
   set_temp("qingshu",0);
   return "����һ�������������ϡ�˵��ӻ�������һ���۵���ǧֽ�װ���ţ������㡣\n";
}
