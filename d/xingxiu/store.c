// room: /d/xingxiu/nanjiang.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ���ӻ��̡����������ŵ�̺�����ϰ����ڵ�̺�ϣ��Ա߶���
���Ļ���ǽ���и����ӣ��Ǹ���Ŀ��(sign)��
LONG
	);
	set("exits", ([ 
	    "east" : __DIR__"yili",
	]));
	set("objects", ([
		__DIR__"npc/maimaiti": 1
	]) );
	set("item_desc", ([ /* sizeof() == 1 */
"sign" : "������д����

��ԭǮ��ͨ�á�

       ���̾ƺ�(hu)           һ����
       ��(nang)	              ��ʮ��
       ����(fire)             һ����
       ���ܹ�(gua)            ��ʮ��
       ������(dongbula)       һ����
       �䵶(wandao)       һǧ�����
       ��Ƥ(yangpi)           ������
       ������(horse)          һǧ�� ( ���� )
\n"
	]));
//	set("no_clean_up", 0);
	set("coor/x", -39100);
	set("coor/y", 13000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

 
