// Feb. 6, 1999 by Winder
inherit NPC;
string inquiry_shoupa();
void create()
{
	set_name("����", ({ "wen yi","wen","yi"}) );
	set("gender", "Ů��" );
        set("title", "�¼�С��");
	set("age", 18);
	set("long", "����һ���������ɵ�Ů�ӣ�ü���ȴ�Ƿ·����������ǡ�\n");
	set("shen_type", 1);
	set("combat_exp", 500);
	set("str", 16);
	set("dex", 17);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	set("chat_chance",1);
	set("chat_msg",({
	    "���Ǿ���������,˫����������Ŵ��⡣\n",
	    "�������������˵���ɾ�������ΪʲôҪ����Ұ�������\n",
	    "������Ȼ���£�������������е�������\n",
            "ͻȻ�䣬���ǵ���ɫ��ò԰���������...��..�������Ӹ�......\n"
	   }) );
       set("inquiry",([
	   "����" : (: inquiry_shoupa :),
           "�����ɾ�" : "��������Ŀ��Ӣ�۵��ɾ�....",
	   ]) );
       set_temp("shoupa",1);
       setup();
        carry_object("/d/city/obj/necklace")->wear();
        carry_object("/d/city/obj/pink_cloth")->wear();
        carry_object("/d/city/obj/flower_shoe")->wear();
        carry_object("/d/city/obj/goldring")->wear();
}
string inquiry_shoupa()
{
 object me=this_player();
 object obn;
 message_vision("����˵������λ"+ RANK_D->query_respect(me)+"�����ܰ��Ҹ�æ����ֻ�������ɾ�֪���ҵ����⡣\n", me );
 if(query_temp("shoupa")==0)
 {  message_vision("������˵������λ"+ RANK_D->query_respect(me)+"�����Ѿ����˰��Ҵ��ˣ��Ͳ��鷳���ˡ�\n",me);
   return "";
 }
   message_vision("����˵������λ"+ RANK_D->query_respect(me)+"�������Һ��ɾ������������������֪���ҵ������ˡ�\n" , me);
   obn=new("/d/shiliang/npc/obj/shoupa");
   obn->move(me);
   set_temp("shoupa",0);
   return "����һ�������������ϣ�������ׯ����ɽ���С�˵�꣬���Ǹ���һ���廨��������\n";
}
