inherit __DIR__"shashou";

void create()
{
  ::create();
	set("level",4);
	set_name("����ɱ��", ({"sha shou", "shashou", "hui", "huiyi"}));
	set("long", "������ɱ�ŵĻ���ɱ�֡�\n");
	set("qi", 1500);
	set("max_qi", 1500);
  set("eff_qi", 1500);
	set("jing", 1500);
	set("max_jing", 1500);
  set("eff_jing", 1500);
	set("neili", 2500);
	set("max_neili", 2500);
  set("combat_exp", 600000);
  set("min_kill_exp", 200000);
  set("base_level",120);
  set("special_level",150);
	set_skill("force",          query("base_level"));
	set_skill("taiji-shengong", query("special_level"));
	set_skill("unarmed",        query("base_level"));
	set_skill("taiji-quan",     query("special_level"));
	set_skill("dodge",          query("base_level"));
	set_skill("tiyunzong",      query("special_level"));
	set_skill("sword",          query("base_level"));
	set_skill("taiji-jian",     query("special_level"));
	set_skill("parry",          query("base_level")); 
	map_skill("force", "taiji-shengong");
	map_skill("unarmed", "taiji-quan");
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
  create_family("��ɱ��", 11-query("level"), "ɱ��");
}