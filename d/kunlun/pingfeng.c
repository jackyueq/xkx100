// Room: /d/kunlun/pingfeng.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ʯ����");
	set("long",@long
����һ���޴�����磬������ɽ�ز��ĺ������ɣ������ϵ�ͼ��
�������ɵ�ʦ��������ʥ�������ս���ֵķ��ˣ�Ӣ��ͦ�Σ�����һ��
��ʦ֮�����������������ɵ�ǰ���ˡ�
long);
	set("exits",([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"qianting",
	]));
	set("objects",([
		CLASS_D("kunlun")+"/first" : 1,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40050);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
