// Room: /d/kunlun/linggong.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"���Ṭ"NOR);
	set("long", @LONG
������һ������֮�⣬ֻ�����ϱ����д�š����Ṭ������Ѫ���
�֡�һ������������һ����������ʮ��ͷ�۽��Ͷ�Ĵ�Ȯ���ֳ�����
���ڵ��ϣ�һ�����׹��õ�Ů������һ�Ż�Ƥ���ϣ�����ִƤ�ޣ���
��ָ�Ӷ�Ȯҧ�ˡ��ϱ���һ����Ժ�ӡ�
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"hmszhouyuan",
	]));
	set("objects",([
		__DIR__"npc/goupu" :  1,
		__DIR__"npc/dog"   :  1,
		__DIR__"npc/dog1"  :  1,
		__DIR__"npc/dog2"  :  1,
		__DIR__"npc/dog3"  :  1,
	]));
	set("coor/x", -90020);
	set("coor/y", 10030);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
