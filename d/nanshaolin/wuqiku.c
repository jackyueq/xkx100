// Room: /d/nanshaolin/wuqiku.c
// Last Modified by winder on May. 29 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����µ�������ɳ����µ�һ��ʮ�˰�����������νӦ�о��С�
����һ��������ٸ��ۻ����ҡ�ǽ������һ����С���ӣ�ÿ����������
���ָ����ı�����ǽ��һ����׳��ɮ����ƹƹ���ҵ��ڴ���һ�����ȡ�
��һλ����ɮ������ǽ�Ƿ���һ�ѽ䵶�������������������������
��ӭ�˹�����
LONG );
	set("exits", ([
		"south" : __DIR__"lshuyuan",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangchen" : 1,
		WEAPON_DIR+"sword/zhujian" : 1,
		WEAPON_DIR+"blade/mudao" : 1,
	]));
	set("coor/x", 1790);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

