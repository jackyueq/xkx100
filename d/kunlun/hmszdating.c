// Room: /d/kunlun/hmszdating.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"ɽׯ����"NOR);
	set("long", @LONG
������ɽׯ���֮��������֮�����Ŵ˼�ׯ����ÿ����ڣ�������
�����ڴ˵Ⱥϣ����������һЩ���ӡ��������Է�����������ӺͲ�
�����ǹ��������ġ�������ȻԶ����ԭ��������֮��ȴ�ǵ��治�١���
�б��Ϲ���һ���ͻ�֮ͼ�������м���ͯ�����ص��̺��š�
LONG	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"hmszhuang",
		"north" : __DIR__"hmsznuange",
		"east"  : __DIR__"hmszhouyuan",
	]));
	set("objects",([
		__DIR__"npc/zhu"  :  1,
	]));
	set("coor/x", -90030);
	set("coor/y", 10020);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
