// ZhuangZheng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
	object ob;
	set_name("ׯ�", ({ "zhuang zheng", "zhuang", "zheng", }));
	set("long",
	"����һλ�ߴ��ΰ���������ӣ���һ���ײ����ۡ�\n"
	"���������������е���ͷ����������򲻵�֮�£�����һ���������ݵĺ��ӡ�\n"
	);

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "fighter");

	set("age", 42);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 85);
	set_skill("hunyuan-yiqi", 85);
	set_skill("dodge", 85);
	set_skill("shaolin-shenfa", 85);
	set_skill("cuff", 95);
	set_skill("jingang-quan", 95);
	set_skill("stick", 95);
	set_skill("dagou-bang", 95);
	set_skill("parry", 85);
	set_skill("buddhism", 85);
	set_skill("literate", 85);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");
	map_skill("stick", "dagou-bang");
	prepare_skill("cuff", "jingang-quan");

	set("party/party_name",HIG"����"NOR);
	set("party/rank",HIW "�����" NOR "����ʹ");
	create_family("����", 35, "����");

	setup();
  if (clonep())
  {
  	ob=new(WEAPON_DIR"treasure/langyabang");
  	if (ob->violate_unique())
  		destruct(ob);
    else
      {
      	ob->move(this_object());
      	ob->wield();
     	}
  	}
	carry_object("/d/mingjiao/obj/baipao")->wear();
}

#include "zhangqishi.h"
