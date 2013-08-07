// waiter.c

#include <ansi.h>
inherit WAITER;
void reset_title();
void create()
{
	set_name("���̻��", ({ "huo ji", "huo", "ji" }));
	set("long", "��������ҵ��̵Ļ�ơ�\n");
	set("gender", "����");
	set("shop", "yangzhou");
	set("age", random(10) + 20);

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}
init()
{
	::init();
	if (query("inited"))
	return;
	reset_title();
	set("inited",1);
}
void reset_title()
{
		object room;
	  if (room=environment())
  {
  if (room->query("waiter/long"))
  set("long",room->query("waiter/long"));
  if (room->query("waiter/title"))
  set("title",room->query("waiter/title"));
  if (room->query("waiter/nickname"))
  set("nickname",room->query("waiter/nickname"));
  if (room->query("waiter/name"))
  set("name",room->query("waiter/name"));
	}
	return;
}
