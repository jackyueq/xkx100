// Room: /d/nanshaolin/chufang2
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ƣ��������ڣ���ζ�˱Ƕ�������ǽ��һ�����ɳ�����̨��
֧��ʮ���ڴ��������һ�ڷ����Ϸ������˴��������ն��£��ֳ�ľ
���ڽ��衣�����շ���ɮ���⣬��λ��ͷ��æ��������н������¯��
���ܡ�һλ����ɮ�������شߴ��š�
LONG );
	set("exits", ([
                "west"  : __DIR__"fanting3",
		"north" : __DIR__"chufang1",
                "south" : __DIR__"xiaolu-1",
	]));
	set("objects",([
		__DIR__"npc/shaofan-seng" : 1,
                __DIR__"npc/hg-toutuo" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

