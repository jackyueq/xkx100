// Room: /d/wuxi/canhetang.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�κ���");
	set("long", @LONG
�κ����������ǵ����ֺ�ҩ���ˣ�ŨŨ��ҩζ���Ѿ�����������
ÿ������֮�У���̨��ļ��ٸ�С���������Ÿ�����ҩ�����ơ�ҩ����
�����ڲ輸�ԣ����Ժ��Ų裬���������ϵ��ʵ���һ��С���վ�ڹ�̨
���к��Ź˿͡���̨������һ�ŷ��ƵĹ��(guanggao)��
LONG );
	set("item_desc", ([
		"guanggao" : "�����������ҩƷ��
��ҩ��\t��ʮ������
�޳������һ�����ҩʦ���䣬������ǣ�
�쾦�����ΰٶ�����Ч������
������ҩ���ϰ����顣\n",
	]));
	set("exits", ([
		"east" : __DIR__"northroad2",
	]));
	set("objects", ([
		"/d/city/npc/huoji" : 1,
	]));
	set("coor/x", 360);
	set("coor/y", -770);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}