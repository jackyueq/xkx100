//Edited by fandog, 02/18/2000
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���Ǿ����ϳ��š���ǽ�ϣ���Ȼ�ɼ�������ʯ������д����Ŀ�֡�
ÿ���ֶ��ǳ��������ԶԶ�������������ġ���ʮһ����ʮ������ʮ��
��������ֵ��ǣ��⼸������ض������ࡣ���߾��Ǿ��ݳ��ˣ��ϱ���
һ��ɽ����������չͨ�����һƬ��ʯ�ԡ�
LONG );
	set("outdoors", "jiangling");
	set("exits", ([
		"south" : __DIR__"shandao1",
		"north" : __DIR__"xijie4",
	]));
	set("objects", ([
		__DIR__"npc/jiaoshu"   : 1,
		"/d/huashan/npc/haoke"  : 2,
		"/d/taishan/npc/jian-ke": 2,
	]));
	set("coor/x", -1500);
	set("coor/y", -2050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}