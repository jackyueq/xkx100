// Room: /d/wuxi/songhe2.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�ɺ�¥��¥");
	set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ�������
�Ժȱ������ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥���ٽ���
�����ɿ����ϳ��������ֵĳ�����������С�����䣬����������򱱿�
����Լ������Ӫ�����ǽ�Ϲ��ż۸�����(paizi)��������һ����ǰ��
һλ����������ǰ���˼������ˮ�ƣ�ȴ�ǲ�����
LONG );
	set("item_desc", ([
		"paizi" : "������۽��ŹǼ��ϵȻ���ơ�\n",
	]));
	set("exits", ([
		"down"    : __DIR__"songhe",
	]));
	set("objects", ([
			__DIR__"npc/jin" : 1,
	]));
	set("coor/x", 380);
	set("coor/y", -810);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}