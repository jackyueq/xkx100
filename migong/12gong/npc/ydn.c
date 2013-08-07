// by happ@YSZZ

inherit NPC;
string ask_cloth();
#include <ansi.h>

void create()
{
   set_name("�ŵ���", ({ "yadian na", "na" }));
   set("long", @LONG

LONG);
   set("gender", "Ů��");
   set("no_get", 1);
   set_temp("no_kill", 1);
   set("age", 20);
   set("attitude", "peaceful");
   set("per",100);//means no rong-mao description.
   set("max_qi", 12000);
   set("max_gin", 14000);
   set("max_jing", 12000);
   set("force", 12000);
   set("max_force", 24000);
   set("force_factor", 500);
   set("max_mana", 14000);
   set("mana", 28000);
   set("mana_factor", 600);
   set("combat_exp", 20000000);
   set("daoxing", 20000000);
   set_skill("spells", 900);
   set_skill("buddhism", 900);
   set_skill("unarmed", 900);
   set_skill("jienan-zhi", 900);
   set_skill("dodge", 900);
   set_skill("lotusmove", 900);
   set_skill("parry", 900);
   set_skill("force", 900);
   set_skill("staff", 900);
   set_skill("lunhui-zhang", 900);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   set("chat_chance_combat", 90);
   set("inquiry",([
      "�ƽ�ʥ��": (: ask_cloth:) ]));

   setup();
  carry_object("/d/migong/12gong/obj/armor")->wear();
   carry_object("/d/migong/12gong/obj/cloth")->wear();
  carry_object("/d/migong/12gong/obj/pifeng")->wear();
     carry_object("/d/migong/12gong/obj/shield")->wear();
carry_object("/d/migong/12gong/obj/staff")->wield();
}

string ask_cloth()
{
        object ob = this_object();
        object me = this_player();
        object cloth;
        if( me->query("12gong/number") >= 12 && !me->query("12gong/all") )
       {
        command("chat "HIY+me->name()+"����ĥ�ѣ����ڵõ��˻ƽ�ʥ�£�");
        me->set("12gongs/all",1);
        me->set("12gong/all",1);
        cloth=new("/d/migong/12gong/npc/obj/gold_cloth.c");
        cloth->move(me);
me->add("combat_exp",300000);
me->add("potential",300000);
return "��õ���,30����,30��Ǳ��,�ƽ�ʥ��һ��!\n
���Ҫע����,���������,�������Լ���ʥ�¸�(drop)��,�ɱ����������Ҫʥ��!";
        }
        return "Ҫ���˻���Ҫʲô?";
}

void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say( "������̫�����˰ɣ�\n");
	command("hehe");
}

void die()
{
	unconcious();
}
