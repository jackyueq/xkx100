//Edited by fandog, 02/15/2000

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("����", ({"lian pen", "pen"}));
	set("unit", "ֻ");
	set("no_get", 1);

	set("long", "����һֻ��֮ͨ�������̣�����װ����ˮ��\n");
	setup();
}
