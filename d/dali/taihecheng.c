//Room: /d/dali/taihecheng.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","̫�ͳ�");
	set("long",@LONG
�˳�����������θ���ȫ����İ����ʯ�ݳɣ������࣬��������
���ϡ�̫�Ͳ����ǣ����˿�Ϊ�������٣������Ϻ;������Ǵ����
�ı��Ż������������������ڴ˼ӹ̳ǳأ���פ������������һЩ��
�Ĳ���۾ӡ�������һƬƽԭ����ʮ���������ǡ�
LONG);
	set("outdoors", "dalin");
	set("objects",([
	    __DIR__"npc/bing": 2,
	    __DIR__"npc/jiang": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"dehuabei",
	    "south"  : __DIR__"dalinorth",
	]));
	set("coor/x", -40000);
	set("coor/y", -50000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}