// map.c
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( HIC "����������ͼ��" NOR, ({ "luyou tu", "tu" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @TEXT
                 ����������ͼ��
                                                                         ���
                                                                     ����ɽ��/
                                                              ��ͼ������ �� /
                                                                            /
                             ��                                     ����Զ  /
 ���շ�                     ����  ��  ��                      ɽ����  _/-\ /
  �ġ� ��ɽɽ��                  �֡֡֡�         �˴���    ͹͹��  _/   |/
   �ġġģ�ġ�  �˼����ء֡֡� ��      ��          ��͹͹͹��    _/  �� ��
���޺��� ����  �ˡ˰�͹͹͹   ��         ��   ��͹͹͹ ����   ___/ �� �� �� ��
         �ˡˡˡˡˡˡˡˡ� ��͹͹͹     ��͹͹͹ƽ���� �� ��/ �� ������������
����ɽ  �ˡ˴�ˡˡˡ�Į�ˡˡˡ�   ��͹͹͹��  ��  ��    ����\___ �� ���� ��
  ��  �ˡˡˡˡˡˡˡˡˡˡˡˡˡˡ�       ���ľ�� ����ɽ   �֡�\_/---+__
�ˡˡˡˡˡˡˡˡ�     ��        ��  ��ɽ���             �֡� ̩ɽ    __/
 �ˡˡˡˡˡˡ�       ����      ����   ���������ɽ�� �֡֡�    ��   _/   ��
�ġ�  �� �� ɽ ��           ������      ��ɽ�֡֡֡֡�  ����       _/ �� ��
    �ġġ� �ġġ� �ġ�           ������ɽ                ��        |__  ����
                             ���У� ��         ����ɽ       ����    \_  ��
                                  ���ȹ�            ������   �� ������\_��
  ��   ��   ��   ԭ                         ��    ��      ������֡��|_��
                    ��                    �䵱ɽ ����       �֡�   ���ˡ�| ���� 
��                   ��   ���ɽ  �ɶ�     ���ݣ��      �֡�  ���ݡ�--_������ 
  _�ġ�             ��ѩɽ   ��     ��       �֡�  �֡֡֡�        ��   / �һ���
   \___�ġ�           ��       ����ɽ     �֡� ��      ��         ����  | ��
       \____�ġ�       �ġ�      ��    �֡�                            _/ ��
  ��ע��   \_ �� ��       ��        �֡�         ��ɽ         ��       |  ��
             -__--\        ��    �֡�   ��        ��     ���ġ� �� ����| ��
  ��  �׶�         | ����   �֡֡�   Ħ����      ����� ɽ���� ��ƽ ��/  ��
  ��  ����       _/ ���� ����                                      /��̨��_
  ��  С��       |_��ɽ ��ϲ��                ����ġ� �ġ�  Ȫ�ݡ�_/���� / |
  ��  ɽ��         |_   ����ɽ                        ��ɽ       _/���衫/  |
����  ��ɽ           \_   ��  ___                      ��       / �������\/
���  ����             |_  _--  \__                 ����___---  �� ��  ��
  ��  ��               \_|       \__              ___---  �� ���� ��������
  ��  ɳĮ                            \__--\  ___--- �� ������ ���� ����
  ��  �ۿ�                            / �� | /  ���� ������  �� ���� ����
  ��  ����                            | ��  \| ������  ���� �� ������ ������
  ��  ����                           / �� ��__--_�� �� ���͵������� �� ������
  ��  ����                           | ��  /    /���� �衫 ������ �� ��������
                                    /   �� --__-  �� ������ �������� ������
TEXT);
		set("value", 50);
		set("material", "paper");
	}
	setup();
}