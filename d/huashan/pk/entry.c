#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���������");
	set("long", @LONG
���������±��ϵ�һС��յأ�������һƬï�ܵ����֣�
����ں����ģ�Ҳ��֪��ͨ�����
LONG);
	       
        set("no_fight", 1);
        set("no_quit",1);
        set("no_sleep_room",1);
	setup();
}
