// Room: /d/suzhou/zijinan.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�Ͻ���");
	set("long", @LONG
����һ�����ݳ������������֣������������ͼ�Ħ����ۣ��ƺ���
ע��ǰ�����֮�ˣ��ұ�һ��������������ָ����һ��������廨����
�ͺ�ڹ�������ͷ�ϵ�һ������ĵ�������Ϻ�ɫ���ǡ���ڵ�ÿ���޺�
�����������������������������������˻������񳬺�����֮�������
�����磬����̾Ϊ��ֹ��
LONG );
	set("objects", ([
		__DIR__"obj/box" : 1,
		__DIR__"npc/nigu1" : 1,
		__DIR__"npc/nigu2" : 1,
	]));
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("no_fight", "1");
	set("exits", ([
		"east"      : __DIR__"beidajie2",
	]));
	set("coor/x", 840);
	set("coor/y", -980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

