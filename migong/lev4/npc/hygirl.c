inherit NPC;
#include <ansi.h>
inherit F_MASTER;
inherit F_DEALER;
inherit F_UNIQUE;
void greeting(object ob);
int do_kiss(string arg);
void create()
{
set_name(HIY"�����콾"NOR, ({"hygirl", "girl"}));
set("title", HIW"��Ů"NOR);
set("gender", "Ů��");
set("age", 16);
set("long",
HIG "������Ʊ����Ů��ʮ�ֹ��ɣ�����ϲ����\n"
NOR);
set("str", 50);
 set("int", 90);
 set("con", 80);
 set("dex", 80);
 set("per", 50);
set("qi", 50000);
set("max_qi", 50000);
set("jing", 30000);
set("max_jing", 30000);
set("neili", 90000);
set("max_neili", 90000);
set("jiali", 300);
set("combat_exp", 10000000);
set("score", 0);
set_skill("force", 500);
set_skill("taixuan-gong", 500);
set_skill("taiji-shengong", 500);
set_skill("kurong-changong", 500);
set_skill("beiming-shengong", 500);
 set_skill("unarmed", 400);
set_skill("anranxiaohun-zhang", 400);
set_skill("dodge", 400);
set_skill("lingboweibu", 400);
set_skill("parry", 400);
set_skill("sword", 400);
set_skill("taiji-jian",400);
set_skill("strike", 400);
set_skill("huoyan-dao", 400);
set_skill("finger", 400);
set_skill("six-finger", 400);
set("chat_chance_combat", 90);
set("chat_msg_combat", ({
(: perform_action, "dodge.lingbo" :),
(: perform_action, "strike.fen" :),
(: perform_action, "dodge.lingbo" :),
(: perform_action, "unarmed.xiaohun" :),
(: command("unwield jian") :),
(: command("wield jian") :),
(: perform_action, "finger.liumaijingshen" :),
(: perform_action, "finger.liumaijingshen" :),
(: perform_action, "sword.lian" :),
(: perform_action, "sword.chan" :),
(: perform_action, "sword.lian" :), 
 }) );
map_skill("force"  , "taiji-shengong");
map_skill("unarmed", "anranxiaohun-zhang");
map_skill("dodge"  , "lingboweibu");
map_skill("sword"  , "taiji-jian") ;
map_skill("finger"  , "six-finger");
map_skill("parry"  , "taiji-jian");
map_skill("strike"  , "huoyan-dao");
prepare_skill("finger", "six-finger");
create_family("��Ʊ", 2, "��Ů");
set("inquiry", ([       
"��Ʊ" : "��Ʊ���ҵ�����!�й����˵��¿������ҡ� ",
"����" : "���˴�Ż���˯����������������post"
]) );  
          set("vendor_goods", ({
              "/d/migong/obj/jiudai",
               "/d/migong/obj/kaoya",
             "/d/migong/obj/jitui",
             "/d/migong/obj/banzi",
           "/d/migong/obj/whip",
           "/d/migong/obj/yinlun",
          "/d/migong/obj/sword2",
          "/d/migong/obj/dao",
          "/d/migong/obj/zhang",
          "/d/migong/obj/guan",
         "/d/migong/obj/jia",
         "/d/migong/obj/shield",
          "/d/migong/obj/wan",
        "/d/migong/obj/dan",
        "/d/migong/obj/chan",
         "/d/migong/obj/wan2",
         "/d/migong/obj/xuelian",
                 }));

setup();
carry_object("/d/tiezhang/obj/ycj.c")->wield();
}
void init()
{
object ob;
::init();
if( interactive(ob = this_player()) && !is_fighting() ) 
{
remove_call_out("greeting");
call_out("greeting", 1, ob);
}
   add_action("do_list", "list");
   add_action("do_buy", "buy");
}
void greeting(object ob)
{
if (!ob || environment(ob) != environment())
 return;
if ((string)ob->query("id") == "cash")
{
 command("jump cash");
message_vision(HIM "\n�����콾���˵�˵�������������������� \n"NOR, ob);
}
else
{
command("wanfu "+(string)ob->query("id"));
message_vision(HIY"\n�����콾�����˵������"+RANK_D->query_respect(ob)+"��ӭ���ٱ��ꡣ�� \n"NOR, ob);
}
}
void attempt_apprentice(object ob)
{
command("say ���ʦ������ȥ����������Ʊ�ɣ�");
}


