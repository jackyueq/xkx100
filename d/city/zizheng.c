// Room: /d/city/zizheng.c
// Last Modified by winder on Apr. 10 2000

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "������Ժ");
	set("long", @LONG
������Ժ�����ݹٰ����Ժ�������˴���С���ʹ˴�����ʶ�֡�
������Ժ��Ժ��һ��Ժ�ӣ��м��ʯ����һ����ɽ������ѧͯ�ڼ�ɽ��
����ȥ�����ϴ�һ��ǧ������Ůѧͯ��ˣ��ǧ�棬���߸���һС���
�°ڼ���ľ����һ��ѧͯ�������ϣ��������ƺ���˯��������ʯ������
�����ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"caohebeijie",
		"north" : __DIR__"tangwu2",
		"south" : __DIR__"zhonglieci",
	]));
	set("objects", ([ /* sizeof() == 3 */
		__DIR__"npc/lixiaoqi" : 1,
		__DIR__"npc/kongxiaotian" : 1,
		__DIR__"npc/guyueer" : 1,
	]));
	set("coor/x", -30);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
