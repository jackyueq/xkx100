//Room: heilong2.c ������ջ��
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","������ջ��");
      set("long",@LONG
������ջ���غ���������������һɽ�п������²������γ�һ��������ߣ�
���Ｘ���׵���Ͽ��������Ͽ��������ջ���ʹ���խ�İ���Ͽ��ת�۴�������
���ھ����ϡ�����ջ���ϣ�ֻ����խ��Σ�������������������ɽ����������
����ͷ���������϶���¿������ϡ�������쿪��ͼ�ġ�һ���졹��ջ����ͨ
ǧ���֣�����������
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "south"    : __DIR__"qianfoan",
          "north"    : __DIR__"heilong1",
      ]));
      set("objects", ([
          "/clone/medicine/vegetable/gancao" : random(2),
      ]));
	set("coor/x", -6130);
	set("coor/y", -1050);
	set("coor/z", 80);
	setup();
      replace_program(ROOM);
}