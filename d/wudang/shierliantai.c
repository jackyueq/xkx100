//Room: shierliantai.c ʮ����̨
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","ʮ����̨");
      set("long",@LONG
�������䵱������ʮ����̨��̨��̨֮����������������̾�����
��Զ����������ڡ�վ����̨��������������ǧҶ����֮�ϣ�ǧ������
���ڽ��¡������������߰�����Ļ�ɽ��������ˮ�������塢��һ��
�����۵ס�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "east"     : __DIR__"jinding",
      ]));
      set("objects", ([
          "/clone/medicine/vegetable/huoxiang" : random(2),
      ]));
      set("outdoors", "wudang");
	set("coor/x", -2040);
	set("coor/y", -1040);
	set("coor/z", 180);
	setup();
      replace_program(ROOM);
}
