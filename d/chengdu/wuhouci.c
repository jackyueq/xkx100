// Room : /d/chengdu/wuhouci.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG

          ة�����úδ�Ѱ�����ٳ����ɭɭ��
          ӳ�ױ̲��Դ�ɫ����Ҷ���պ�����
          ����Ƶ�����¼ƣ����������ϳ��ġ�
          ��ʦδ������������ʹӢ��������

    ������Ǳ����˾���������������ﰲ��������ʱ����һ���ͳ���
���������гɶ������˺��ο�ǰ���ΰݡ����ܲ�����������ž޴���Ĺ��
�����ϲ�ʱ����������ü�����Ľ����������š���ʦδ������������
���в��ɵ�һ����Ȼ������������Ĺ��
LONG	);
        set("exits", ([
		"west"      : __DIR__"lingmu",
		"northup"   : __DIR__"liubeidian",
		"southeast" : __DIR__"wuhoucigate",
	]));
        set("outdoors", "chengdu");
        set("coor/x", -8070);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

