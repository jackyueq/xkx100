// /kaifeng/xiangguosi.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�������ռ�������Ķ��Ͻ��ʮ�ĸ�������Ժ����ɮǧ�ࡣ�Ǿ���
������Ժ��ȫ����̻���ġ���ǰ��������¡����Ҷ����ǵ�����
�����顣���ų�������������������
LONG);
	set("objects", ([
		__DIR__"npc/zhike" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"qianyuan",
		"south" : __DIR__"jiedao",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
