// Room: /d/lingxiao/laolang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
���������Ǽ��������ȣ����߹صĶ��������Ƿ����Ź�ĵ��ӡ���
�����¸ߵͲ�ƽ�����߶��Ǿ�ʯ���ɣ�һ�����ؽ������ͱ����ӵó�ȥ��
ǽ�ϵ���һ֧֧��ѣ�����յ�����ǽ�ϵ�Ӱ����Ҫ���˶��ɵĹ���һ
�������������ֵط����ǿ��߱ȽϺá�
LONG );
	set("exits", ([
		"up" : __DIR__"jianyuting",
		"west" : __DIR__"jianyusun",
		"east" : __DIR__"jianyuzhu",
		"down" : __DIR__"didi",
	]));
	set("objects", ([ 
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -30990);
	set("coor/y", -8900);
	set("coor/z", 130);
	setup(); 
	replace_program(ROOM);
}

