// Room: /d/songshan/huimengtang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ԭ���Ǿ�����Ժ�Ĵ��۱�����������ɰ���ǰ�ڴ��ѪΪ��
����������ͳ��������������������ˡ��������з���һ�ŻƳ�̫ʦ��
�Σ����������ı�������������������̩�������⡢������ء��׶С�
���ޡ�������Σ��κ���Ÿ��ɵ���ɫ�졣
LONG );
	set("exits", ([
		"south" : __DIR__"zhongmen",
		"north" : __DIR__"jianchi",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/zuo" : 1,
	]));
	set("coor/x", -20);
	set("coor/y", 890);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
